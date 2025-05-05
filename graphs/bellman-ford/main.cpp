#include <iostream>
#include <list>
#include <vector>
#include <queue>

class Graph
{
private:
   int vertices;
   bool isDirected;
   std::vector<std::list<std::pair<int, int>>> adjList;
   std::vector<bool> visited;

public:
   Graph(int v, bool isDirected = false) : vertices(v), adjList(v), visited(v, false), isDirected(isDirected) {}

   void addEdge(int u, int v, int w)
   {
      adjList[u].push_back({u, w});

      if (!isDirected)
      {
         adjList[v].push_back({u, w});
      }
   }

   void print()
   {
      for (int i = 0; i < vertices; i++)
      {
         std::cout << i << ": ";
         for (auto edge : adjList[i])
         {
            std::cout << "(" << edge.first << ", " << edge.second << ") ";
         }
         std::cout << std::endl;
      }
   }
};

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

   g.print();

   return 0;
}