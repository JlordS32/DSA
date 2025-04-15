#include <iostream>
#include <vector>

class Graph
{
private:
   int vertices;
   std::vector<std::vector<int>> adjMatrix;

public:
   Graph(int vertices) : vertices(vertices), adjMatrix(vertices, std::vector<int>(vertices, 0)) {}

   void addEdge(int u, int v)
   {
      adjMatrix[u][v] = 1;
      adjMatrix[v][u] = 1;
   }

   void print()
   {
      for (int i = 0; i < vertices; i++)
      {
         std::cout << "[ ";
         for (int j = 0; j < vertices; j++)
         {
            std::cout << adjMatrix[i][j] << " ";
         }
         std::cout << "]" << std::endl;
      }
   }
};

main()
{

   Graph g(4);

   g.addEdge(0, 1);
   g.addEdge(0, 2);
   g.addEdge(3, 1);
   g.addEdge(3, 2);

   g.print();

   return 0;
}