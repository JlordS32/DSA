#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

class Graph
{
private:
   int vertices;
   bool isDirected;
   std::vector<std::vector<int>> adjMatrix;
   const int INF = std::numeric_limits<int>::max();

public:
   Graph(int v, bool isDirected = false)
       : vertices(v), isDirected(isDirected), adjMatrix(v, std::vector<int>(v, INF))
   {
      for (int i = 0; i < v; ++i)
         adjMatrix[i][i] = 0;
   }

   void addEdge(int u, int v, int w)
   {
      adjMatrix[u][v] = w;
      if (!isDirected)
      {
         adjMatrix[v][u] = w;
      }
   }

   void print()
   {
      for (int i = 0; i < vertices; i++)
      {
         for (int j = 0; j < vertices; j++)
         {
            if (adjMatrix[i][j] == 0)
               std::cout << std::setw(5) << "0";
            else
               std::cout << std::setw(5) << adjMatrix[i][j];
         }
         std::cout << std::endl;
      }
   }

   void floydWarshall()
   {
      std::vector<std::vector<int>> dist = adjMatrix;

      for (int k = 0; k < vertices; k++)
      {
         for (int i = 0; i < vertices; i++)
         {
            for (int j = 0; j < vertices; j++)
            {
               if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
               {
                  dist[i][j] = dist[i][k] + dist[k][j];
               }
            }
         }
      }

      for (int i = 0; i < dist.size(); i++)
      {
         for (int j = 0; j < dist.size(); j++)
         {
            if (dist[i][j] == INF)
               std::cout << std::setw(5) << "0";
            else
               std::cout << std::setw(5) << dist[i][j];
         }
         std::cout << std::endl;
      }
   }
};

int main()
{
   Graph g(4, true); // Directed graph with 4 nodes (0-based index)

   g.addEdge(0, 2, -2); // 1 → 3
   g.addEdge(2, 3, 2);  // 3 → 4
   g.addEdge(3, 1, -1); // 4 → 2
   g.addEdge(1, 0, 4);  // 2 → 1
   g.addEdge(1, 2, 3);  // 2 → 3

   g.floydWarshall();

   return 0;
}