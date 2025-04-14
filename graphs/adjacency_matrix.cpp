#include <iostream>
#include <vector>

class Graph
{
private:
   int vertices;
   std::vector<std::pair<int, int>> edges;
   std::vector<int> adjMatrix;

public:
   Graph(int vertices) : vertices(vertices), adjMatrix() {}

   void addEdge(int u, int v) {
      edges.push_back({u, v});

   }
};

int
main()
{

   return 0;
}