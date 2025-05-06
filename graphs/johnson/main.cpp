#include <iostream>
#include <limits>
#include <algorithm>
#include "../graph.hpp"

const int MAX_INT = std::numeric_limits<int>::max();

std::vector<int> bellmanFord(Graph &g, int source)
{
   // Initialise a distance vector of size = number of vertices, with initial value = MAX_INT
   std::vector<int> dist(g.getVertices(), MAX_INT);

   // We set the source distance to 0.
   dist[source] = 0;

   // For the outer loop: Loop about | V | - 1 times to relax all edges.
   // This allows us to find all possible shortest paths
   for (int i = 0; i < g.getVertices() - 1; i++)
   {
      // Visit all edges for each vertex.
      for (int u = 0; u < g.getVertices(); u++)
      {
         for (auto &[v, weight] : g.getAdjList()[u])
         {
            if (dist[u] != MAX_INT && dist[u] + weight < dist[v])
            {
               dist[v] = dist[u] + weight;
            }
         }
      }
   }

   // Negative cycle check
   for (int u = 0; u < g.getVertices(); u++)
   {
      for (auto &[v, weight] : g.getAdjList()[u])
      {
         if (dist[u] != MAX_INT && dist[u] + weight < dist[v])
         {
            std::cerr << "Negative weight cycle detected.\n";
            return {};
         }
      }
   }

   std::cout << "Bellman Ford: "; 
   for (int i = 0; i < dist.size(); i++)
   {
      std::cout << i << ": " << dist[i] << "\n";
   }

   return dist;
}

std::vector<int> dijkstras(Graph &g, int source)
{
   // 1. Mark all nodes unvisited.
   // 2. Make distance vector for all nodes.
   // 3. Set source distance to 0.
   std::vector<int> dist(g.getVertices(), MAX_INT);
   std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
   dist[source] = 0;

   int current = source;
   pq.push({0, source}); // distance = 0, node = source

   while (!pq.empty())
   {
      int current = pq.top().second;
      pq.pop();

      for (auto &[neighbor, weight] : g.getAdjList()[current])
      {
         if (dist[current] + weight < dist[neighbor])
         {
            dist[neighbor] = dist[current] + weight;
            pq.push({dist[neighbor], neighbor});
         }
      }
   }

   return dist;
}

void johnson(Graph &g)
{
   // Add virtual node to the graph
   g.addVertex();
   int virtualNode = g.getVertices() - 1;

   // Add edge with a weight of 0 to every node.
   for (int i = 0; i < g.getVertices(); ++i)
   {
      g.addEdge(virtualNode, i, 0);
   }

   // Run bellman ford
   std::vector<int> h = bellmanFord(g, virtualNode);
   if (h.empty())
      return;

   // Clear the edge
   g.removeEdgesFrom(virtualNode);

   // Reweighting, making a copy approach
   Graph reweightedG(g.getVertices(), true);
   for (int u = 0; u < g.getVertices(); ++u)
   {
      for (auto &[v, w] : g.getAdjList()[u])
      {
         int newWeight = w + h[u] - h[v];
         reweightedG.addEdge(u, v, newWeight);
      }
   }

   for (int u = 0; u < g.getVertices(); ++u)
   {
      std::vector<int> dPrime = dijkstras(reweightedG, u);

      for (int v = 0; v < g.getVertices(); ++v)
      {
         if (dPrime[v] == MAX_INT)
            std::cout << u << " -> " << v << ": inf\n";
         else
            std::cout << u << " -> " << v << ": " << dPrime[v] - h[u] + h[v] << "\n";
      }
      std::cout << std::endl;
   }
}

int main()
{
   Graph g(4, true); // 4 nodes, directed

   g.addEdge(0, 1, 1);  // 0 → 1
   g.addEdge(0, 2, 4);  // 0 → 2
   g.addEdge(1, 2, -3); // 1 → 2
   g.addEdge(2, 3, 2);  // 2 → 3
   g.addEdge(3, 1, 7);  // 3 → 1

   johnson(g);

   return 0;
}
