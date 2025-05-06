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
   const int INF = std::numeric_limits<int>::max(); // Represents no connection

public:
   Graph(int v, bool isDirected = false)
       : vertices(v), isDirected(isDirected), adjMatrix(v, std::vector<int>(v, INF)) {}

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
      std::cout << "Adjacency Matrix:\n";
      for (int i = 0; i < vertices; i++)
      {
         for (int j = 0; j < vertices; j++)
         {
            if (adjMatrix[i][j] == INF)
               std::cout << std::setw(5) << "∞";
            else
               std::cout << std::setw(5) << adjMatrix[i][j];
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

   g.print();

   return 0;
}
