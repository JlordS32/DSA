#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <iostream>
#include <fstream>
#include <utility>
#include <functional>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <limits>

template <typename T>
class Graph
{
private:
   std::vector<std::unordered_map<int, T>> adjList{};
   int numVertices{};

public:
   // empty graph with N vertices
   explicit Graph(int N);

   // construct graph from edge list in filename
   explicit Graph(const std::string &filename);

   // add an edge directed from vertex i to vertex j with given weight
   void addEdge(int i, int j, T weight);

   // removes edge from vertex i to vertex j
   void removeEdge(int i, int j);

   // is there an edge from vertex i to vertex j?
   bool isEdge(int i, int j) const;

   // return weight of edge from i to j
   // will throw an exception if there is no edge from i to j
   T getEdgeWeight(int i, int j) const;

   // returns number of vertices in the graph
   int size() const;

   // return iterator to a particular vertex
   const std::unordered_map<int, T> &neighbours(int a) const
   {
      return adjList.at(a);
   }
};

template <typename T>
Graph<T>::Graph(int N) : adjList(N), numVertices{N} {}

template <typename T>
Graph<T>::Graph(const std::string &inputFile)
{
   std::ifstream infile{inputFile};
   if (!infile)
   {
      std::cerr << inputFile << " could not be opened\n";
      return;
   }
   // first line has number of vertices
   infile >> numVertices;
   adjList.resize(numVertices);
   int i{};
   int j{};
   double weight{};
   // assume each remaining line is of form
   // origin dest weight
   while (infile >> i >> j >> weight)
   {
      addEdge(i, j, static_cast<T>(weight));
   }
}

template <typename T>
int Graph<T>::size() const
{
   return numVertices;
}

template <typename T>
void Graph<T>::addEdge(int i, int j, T weight)
{
   if (i < 0 or i >= numVertices or j < 0 or j >= numVertices)
   {
      throw std::out_of_range("invalid vertex number");
   }
   adjList[i].insert({j, weight});
}

template <typename T>
void Graph<T>::removeEdge(int i, int j)
{
   // check if i and j are valid
   if (i >= 0 && i < numVertices && j >= 0 && j < numVertices)
   {
      adjList[i].erase(j);
   }
}

template <typename T>
bool Graph<T>::isEdge(int i, int j) const
{
   if (i >= 0 && i < numVertices && j >= 0 && j < numVertices)
   {
      return adjList.at(i).contains(j);
   }
   return false;
}

template <typename T>
T Graph<T>::getEdgeWeight(int i, int j) const
{
   return adjList.at(i).at(j);
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Graph<T> &G)
{
   for (int i = 0; i < G.size(); ++i)
   {
      out << i << ':';
      for (const auto &[neighbour, weight] : G.neighbours(i))
      {
         out << " (" << i << ", " << neighbour << ")[" << weight << ']';
      }
      out << '\n';
   }
   return out;
}

// APSP functions
// Use this function to return an "infinity" value
// appropriate for the type T
template <typename T>
T infinity()
{
   if (std::numeric_limits<T>::has_infinity)
   {
      return std::numeric_limits<T>::infinity();
   }
   else
   {
      return std::numeric_limits<T>::max();
   }
}

template <typename T>
std::vector<T> bellmanFord(const Graph<T> &G, int source = 0)
{
   // Set up distance vector
   std::vector<T> dist(G.size(), infinity<T>());

   // Run Bellman-Ford algorithm
   dist.at(source) = 0;
   for (int i = 0; i < G.size() - 1; ++i)
   {
      for (int u = 0; u < G.size(); ++u)
      {
         for (const auto &[neighbour, weight] : G.neighbours(u))
         {
            if (dist.at(u) != infinity<T>() && dist.at(u) + weight < dist.at(neighbour))
            {
               dist.at(neighbour) = dist.at(u) + weight;
            }
         }
      }
   }

   return dist;
}

template <typename T>
std::vector<T> dijkstras(const Graph<T> &G, int source = 0)
{
   // Setup distance vector
   std::vector<T> dist(G.size(), infinity<T>());
   
   // Setup starting node with weight of 0.
   dist[source] = T{};

   // Set up priority queue
   using P = std::pair<T, int>;
   std::priority_queue<P, std::vector<P>, std::greater<>> pq;
   pq.push({T{}, source});

   // Similar implementation to bfs
   while (!pq.empty())
   {
      auto [d, u] = pq.top();
      pq.pop();

      // For each edge in the vertex u
      for (const auto &[v, w] : G.neighbours(u))
      {
         if (dist[u] + w < dist[v])
         {
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
         }
      }
   }

   return dist;
}


// implement an algorithm for determining if G
// has a negative weight cycle here
template <typename T>
bool existsNegativeCycle(const Graph<T> &G)
{
   // Run Bellman-Ford algorithm and get dist vector
   std::vector<T> dist = bellmanFord(G);

   // Check for negative cycle in dist
   for (int u = 0; u < G.size(); ++u)
   {
      for (const auto &[neighbour, weight] : G.neighbours(u))
      {
         if (dist.at(u) != infinity<T>() && dist.at(u) + weight < dist.at(neighbour))
         {
            return true;
         }
      }
   }

   return false;
}

// implement Johnson's APSP algorithm here
template <typename T>
std::vector<std::vector<T>>
johnsonAPSP(const Graph<T> &G)
{
   // 1. Construct new graph with n + 1 vertices.   
   int n = G.size();
   int virtualNode = n;
   Graph<T> virtualG(n + 1);

   // 2. Copy edges from G to virtualG
   for (int u = 0; u < n; ++u) {
      for (const auto& [v, w] : G.neighbours(u)) {
         virtualG.addEdge(u, v, w);
      }
   }

   // 3. Add outging edges from virtual node to all nodes with weight of 0;
   for (int v = 0; v < n; ++v) {
      virtualG.addEdge(virtualNode, v, 0);
   }
   
   // 4. Run Bellman-Ford from starting from virtual node.
   std::vector<T> h = bellmanFord(virtualG, virtualNode);

   // 5. Reweight original graph into a new graph
   Graph<T> reweightedG(n);
   for (int u = 0; u < n; ++u) {
      for (const auto& [v, w] : G.neighbours(u)) {
         T newWeight = w + h[u] - h[v];
         reweightedG.addEdge(u, v, newWeight);
      }
   }
 
   // 6. Run Dijkstras algorithm to every node.
   std::vector<std::vector<T>> result(n, std::vector<T>(n, infinity<T>()));
   for (int u = 0; u < n; ++u) {
      std::vector<T> dPrime = dijkstras(reweightedG, u);
      for (int v = 0; v < n; ++v) {
         if (dPrime[v] != infinity<T>()) {
            result[u][v] = dPrime[v] - h[u] + h[v];
         }
      }
   }

   return result;
}

// implement the Floyd-Warshall APSP algorithm here
template <typename T>
std::vector<std::vector<T>>
floydWarshallAPSP(const Graph<T> &G)
{
   // Set up distance matrix by copying edge weights over for dist[i][j]
   std::vector<std::vector<T>> dist(G.size(), std::vector<T>(G.size(), infinity<T>()));
   for (int i = 0; i < G.size(); ++i)
   {
      for (const auto &[neighbour, weight] : G.neighbours(i))
      {
         dist.at(i).at(neighbour) = weight;
      }
   }

   // Self loop
   for (int i = 0; i < G.size(); ++i)
   {
      dist.at(i).at(i) = T{};
   }

   // Floyd Marshall Algorithm
   for (int k = 0; k < G.size(); k++)
   {
      for (int i = 0; i < G.size(); i++)
      {
         for (int j = 0; j < G.size(); j++)
         {
            // If [i][k] and [k][j] are not infinity and [i][j] is greater than [i][k] + [k][j]
            if (dist[i][k] != infinity<T>() &&
                dist[k][j] != infinity<T>() &&
                dist[i][j] > dist[i][k] + dist[k][j])
            {
               dist[i][j] = dist[i][k] + dist[k][j];
            }
         }
      }
   }

   return dist;
}

#endif // GRAPH_HPP_
