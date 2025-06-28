#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath> 
#include "../graph.hpp"

const int MAX_INT = std::numeric_limits<int>::max();
const int width = 3; 

void dijkstras(Graph &g, int source)
{
   // 1. Mark all nodes unvisited.
   // 2. Make distance vector for all nodes.
   // 3. Set source distance to 0.
   std::vector<int> dist(g.getVertices(), MAX_INT);
   std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
   dist[source] = 0;

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

int heuristic(int a, int b)
{
   int ax = a % width, ay = a / width;
   int bx = b % width, by = b / width;
   return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

void astar(Graph &g, int start, int goal)
{
   std::vector<int> gScore(g.getVertices(), MAX_INT);
   std::vector<int> fScore(g.getVertices(), MAX_INT);
   std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> openSet;

   gScore[start] = 0;
   fScore[start] = heuristic(start, goal);
   openSet.push({fScore[start], start});

   while (!openSet.empty())
   {
      int current = openSet.top().second;
      openSet.pop();

      if (current == goal)
      {
         std::cout << "Reached goal with cost: " << gScore[goal] << std::endl;
         return;
      }

      for (auto edge : g.getAdjList()[current])
      {
         int neighbor = edge.first;
         int weight = edge.second;
         int tentative_g = gScore[current] + weight;

         if (tentative_g < gScore[neighbor])
         {
            gScore[neighbor] = tentative_g;
            fScore[neighbor] = tentative_g + heuristic(neighbor, goal);
            openSet.push({fScore[neighbor], neighbor});
         }
      }
   }

   std::cout << "Goal not reachable\n";
}

int main()
{
   Graph g(6);

   g.addEdge(0, 1, 4);
   g.addEdge(0, 2, 1);
   g.addEdge(2, 1, 2);
   g.addEdge(1, 3, 1);
   g.addEdge(2, 3, 5);
   g.addEdge(3, 4, 3);
   g.addEdge(4, 5, 1);

   astar(g, 0, 4);

   return 0;
}
