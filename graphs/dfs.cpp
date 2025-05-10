#include <iostream>
#include <vector>
#include <list>
#include <limits>

class Graph
{
private:
   int vertices;
   std::vector<bool> on_stack;
   std::list<int> reverse_post_order;
   std::vector<std::list<std::pair<int, double>>> adjList;

public:
   std::vector<bool> visited;
   Graph(int v) : vertices(v),
                  visited(v, false),
                  on_stack(v, false),
                  adjList(v) {}

   void addEdge(int u, int v, double w = 0)
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

      reverse_post_order.push_front(node);
      on_stack[node] = false;
   }

   void print_stack()
   {
      for (int i = 0; i < vertices; i++)
      {
         if (!on_stack[i])
         {
            std::cout << i << " ";
         }
      }
      std::cout << std::endl;
   }

   std::vector<double> shortest_path(int source)
   {
      std::vector<double> dist(vertices, std::numeric_limits<double>::max());
      dist[source] = 0;

      for (int u : reverse_post_order)
      {
         for (auto v : adjList[u])
         {
            if (dist[u] + v.second < dist[v.first])
            {
               dist[v.first] = dist[u] + v.second;
            }
         }
      }

      return dist;
   }
};

int main()
{
   Graph g(6);

   g.addEdge(0, 5, 0.5);
   g.addEdge(0, 1, 2.0);
   g.addEdge(0, 4, -1.0);
   g.addEdge(2, 1, 0.5);
   g.addEdge(2, 3, 1.5);
   g.addEdge(3, 1, 1.0);
   g.addEdge(4, 2, 1.0);
   g.addEdge(4, 3, 1.0);

   for (int i = 0; i < 6; i++)
   {
      if (!g.visited[i])
      {
         g.dfs(i);
      }
   }

   std::vector<double> dist = g.shortest_path(0);

   for (int i = 0; i < dist.size(); i++)
   {
      std::cout << dist[i] << " ";
   }

   return 0;
}