#ifndef GRAPH_HPP_
#define GRAPH_HPP_
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

public:
   Graph(int v, bool isDirected = false) : vertices(v), adjList(v), isDirected(isDirected) {}

   void addEdge(int u, int v, int w)
   {
      adjList[u].push_back({v, w});

      if (!isDirected)
      {
         adjList[v].push_back({u, w});
      }
   }

   void addVertex()
   {
      adjList.push_back({});
      vertices++;
   }

   void removeEdgesFrom(int u)
   {
      adjList[u].clear();
      vertices--;
   }

   void print()
   {
      for (int i = 0; i < vertices; i++)
      {
         std::cout << i << ": ";
         for (auto edge : adjList[i])
         {
            std::cout << edge.second << ", ";
         }
         std::cout << std::endl;
      }
   }

   int getVertices() { return vertices; }
   std::vector<std::list<std::pair<int, int>>> &getAdjList() { return adjList; }
};

#endif