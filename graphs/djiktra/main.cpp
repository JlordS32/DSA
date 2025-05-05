#include <iostream>
#include <limits>
#include <algorithm>
#include "../graph.hpp"

const int MAX_INT = std::numeric_limits<int>::max();

void dijkstras(Graph &g, int source)
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

      for (auto edge : g.getAdjList()[current])
      {
         int neighbor = edge.first;
         int weight = edge.second;

         if (dist[current] + weight < dist[neighbor])
         {
            dist[neighbor] = dist[current] + weight;
            pq.push({dist[neighbor], neighbor});
         }
      }
   }

   for (int i = 0; i < dist.size(); ++i)
      std::cout << i << ": " << dist[i] << std::endl;
}

int main()
{
   Graph g(6); // Undirected by default

   g.addEdge(0, 1, 4);
   g.addEdge(0, 2, 1);
   g.addEdge(2, 1, 2);
   g.addEdge(1, 3, 1);
   g.addEdge(2, 3, 5);
   g.addEdge(3, 4, 3);
   g.addEdge(4, 5, 1);

   dijkstras(g, 0);

   return 0;
}
