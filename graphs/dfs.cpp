#include <iostream>
#include <vector>
#include <list>

class Graph
{
private:
   int vertices;
   std::vector<bool> visited;
   std::vector<bool> on_stack;
   std::vector<std::list<std::pair<int, int>>> adjList;

public:
   Graph(int v) : vertices(v),
                  visited(v, false),
                  on_stack(v, false),
                  adjList(v) {}

   void addEdge(int u, int v, int w = 0)
   {
      adjList[u].push_back({v, w});
   }

   void dfs(int node)
   {
      visited[node] = true;
      on_stack[node] = true;

      for (auto edge : adjList[node])
      {
         int neighbor = edge.first;
         if (!visited[neighbor])
         {
            dfs(neighbor);
         }
      }

      std::cout << node << " ";

      on_stack[node] = false;
   }

   void print_stack() {
      for (int i = 0; i < vertices; i++) {
         if (!on_stack[i]) {
            std::cout << i << " ";
         }
      }
      std::cout << std::endl;
   }
};

int main()
{
   Graph g(6);

   g.addEdge(0, 1);
   g.addEdge(0, 3);
   g.addEdge(1, 2);
   g.addEdge(2, 3);
   g.addEdge(3, 1);
   g.addEdge(4, 5);
   g.addEdge(4, 2);
   g.addEdge(4, 1);

   g.dfs(4);

   return 0;
}