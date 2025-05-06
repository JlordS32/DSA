#include <iostream>
#include <limits>
#include <algorithm>
#include "../graph.hpp"

const int MAX_INT = std::numeric_limits<int>::max();

void bellmanFord(Graph &g, int source)
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
         for (auto &edge : g.getAdjList()[u])
         {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] != MAX_INT && dist[u] + weight < dist[v])
            {
               dist[v] = dist[u] + weight;
            }
         }
      }
   }

   for (int u = 0; u < g.getVertices(); u++)
   {
      for (auto &edge : g.getAdjList()[u])
      {
         int v = edge.first;
         int weight = edge.second;

         if (dist[u] != MAX_INT && dist[u] + weight < dist[v])
         {
            std::cout << "Negative weight cycle detected!" << std::endl;
            return;
         }
      }
   }

   // Print
   for (int i = 0; i < dist.size(); i++)
   {
      std::cout << i << ": " << dist[i] << std::endl;
   }
}

int main()
{
   Graph g(3, true); // 3 nodes

   g.addEdge(0, 1, 1);  // A → B
   g.addEdge(1, 2, -1); // B → C
   g.addEdge(2, 0, -1); // C → A

   bellmanFord(g, 0);

   return 0;
}