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

   // Print
   for (int i = 0; i < dist.size(); i++) {
      std::cout << i << ": " << dist[i] << std::endl;
   }
}

int main()
{
   Graph g(6, true);

   g.addEdge(0, 1, 8);
   g.addEdge(0, 2, 10);
   g.addEdge(1, 3, 1);
   g.addEdge(2, 5, 2);
   g.addEdge(3, 2, -4);
   g.addEdge(3, 5, -1);
   g.addEdge(5, 4, -2);
   g.addEdge(4, 2, 1);

   bellmanFord(g, 0);

   return 0;
}