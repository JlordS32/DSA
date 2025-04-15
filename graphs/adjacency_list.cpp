#include <iostream>
#include <list>
#include <vector>
#include <queue>

class Graph
{
private:
   int vertices;
   std::vector<std::list<int>> adjList;

public:
   Graph(int v) : vertices(v), adjList(v) {}

   void addEdge(int u, int v)
   {
      adjList[u].push_back(v);
      adjList[v].push_back(u);
   }

   void print()
   {
      for (int i = 0; i < vertices; i++)
      {
         std::cout << i << ": ";
         for (int j : adjList[i])
         {
            std::cout << j << " ";
         }
         std::cout << std::endl;
      }
   }

   int totalDegree()
   {
      int degree = 0;
      for (int i = 0; i < vertices; i++)
      {
         degree += adjList[i].size();
      }
      return degree;
   }

   int numberOfEdges()
   {
      return totalDegree() / 2;
   }

   void dfs(int node)
   {
      std::vector<bool> visited(vertices, false);
      dfsHelper(node, visited);
   }

   void dfsHelper(int node, std::vector<bool> &visited)
   {
      visited[node] = true;
      std::cout << node << " ";

      for (int neighbor : adjList[node])
      {
         if (!visited[neighbor])
         {
            dfsHelper(neighbor, visited);
         }
      }
   }

   void bfs(int start)
   {
      std::vector<bool> visited(vertices, false);
      std::queue<int> q;

      int current = start;
      visited[current] = true;
      q.push(current);

      while (!q.empty())
      {
         current = q.front();
         q.pop();

         std::cout << current << " ";

         for (int neighbor : adjList[current])
         {
            if (!visited[neighbor])
            {
               visited[neighbor] = true;
               q.push(neighbor);
            }
         }
      }
   }
};

int main()
{

   Graph g(11);

   g.addEdge(0, 1);
   g.addEdge(0, 5);
   g.addEdge(5, 9);
   g.addEdge(1, 6);
   g.addEdge(6, 7);
   g.addEdge(7, 10);
   g.addEdge(1, 2);
   g.addEdge(2, 3);
   g.addEdge(2, 8);
   g.addEdge(3, 8);

   g.print();

   std::cout << "Total degree: " << g.totalDegree() << std::endl;
   std::cout << "Total edges: " << g.numberOfEdges() << std::endl;

   std::cout << "\nBFS: ";
   g.bfs(0);
   std::cout << "\nDFS: ";
   g.dfs(0);
   return 0;
}