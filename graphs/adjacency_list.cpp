#include <iostream>
#include <vector>

class Graph
{
private:
   int vertices;
   std::vector<std::vector<int>> adjList;

public:
   Graph(int v) : vertices(v), adjList(v) {}

   void addEdge(int src, int dest)
   {
      adjList[src].push_back(dest);
      adjList[dest].push_back(src); // for undirected
   }

   void printList()
   {
      for (int i = 0; i < vertices; ++i)
      {
         std::cout << i << ": ";
         for (int neighbor : adjList[i])
            std::cout << neighbor << " ";
         std::cout << "\n";
      }
   }
};

int main()
{
   Graph g(4);
   g.addEdge(0, 1);
   g.addEdge(0, 2);
   g.addEdge(1, 2);
   g.addEdge(2, 3);

   g.printList();

   return 0;
}
