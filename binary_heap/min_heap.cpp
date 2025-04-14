#include <iostream>
#include <vector>

class MinHeap
{
private:
   using Iterator = std::vector<int>::iterator;
   std::vector<int> heap;

   void swim(std::size_t i)
   {
      std::size_t p = parent(i);
      while (i > 0 && heap[i] < heap[p])
      {
         std::swap(heap[i], heap[p]);
         i = p;
         p = parent(i);
      }
   }

   void sink(std::size_t i)
   {
      std::size_t n = heap.size();
      while (true)
      {
         std::size_t left = 2 * i + 1;
         std::size_t right = 2 * i + 2;
         std::size_t smallest = i;

         if (left < n && heap[left] < heap[smallest])
            smallest = left;
         if (right < n && heap[right] < heap[smallest])
            smallest = right;

         if (smallest == i)
            break;

         std::swap(heap[i], heap[smallest]);
         i = smallest;
      }
   }

public:
   void insert(int key)
   {
      heap.push_back(key);
      swim(heap.size() - 1);
   }

   void remove_min()
   {
      if (heap.empty())
         return;
      for (auto it = heap.begin(); it != heap.end(); ++it)
         std::cout << *it << " ";
      std::cout << std::endl;
      std::swap(*heap.begin(), *std::prev(heap.end()));
      for (auto it = heap.begin(); it != heap.end(); ++it)
         std::cout << *it << " ";
      std::cout << std::endl;
      heap.pop_back();
      for (auto it = heap.begin(); it != heap.end(); ++it)
         std::cout << *it << " ";
      std::cout << std::endl;
      sink(0);
      for (auto it = heap.begin(); it != heap.end(); ++it)
         std::cout << *it << " ";
      std::cout << std::endl;
   }

   Iterator begin() { return heap.begin(); }
   Iterator end() { return heap.end(); }
   std::size_t parent(std::size_t i) { return (i - 1) / 2; }
};

int main()
{
   MinHeap h;
   h.insert(3);
   h.insert(2);
   h.insert(5);
   h.insert(4);
   h.insert(1);
   h.insert(1);
   h.insert(6);

   h.remove_min();

   return 0;
}