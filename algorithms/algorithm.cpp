#include "algorithm.hpp"
#include <map>
#include <iostream>
#include <vector>

// ----------------------
// UTILITIES
// ----------------------
template <typename T>
void swap(T &a, T &b)
{
   T temp = a;
   a = b;
   b = temp;
}

template <typename Iterator>
void copy(Iterator begin, Iterator end, Iterator dest) {
   while (begin != end) {
      *dest = *begin;
      ++begin;
      ++dest;
   }
}

// ----------------------
// BUBBLE SORT
// ----------------------
// Best case: O(n)
// Worst case: O(n^2) -> specially in a reversed sorted array
// Average case: O(n^2) 
template <typename Iterator>
void bubble_sort(Iterator begin, Iterator end)
{
   for (Iterator i = begin; i != end; ++i)
   {
      for (Iterator j = i + 1; j != end; ++j)
      {
         if (*i > *j)
         {
            swap(*i, *j);
         }
      }
   }
}

// ----------------------
// INSERTION SORT
// ----------------------
// Best case: O(n)
// Worst case: O(n^2) -> specially in a reversed sorted array
// Average case: O(n^2) 
template <typename Iterator>
void insertion_sort(Iterator begin, Iterator end)
{
   for (Iterator i = begin; i != end; ++i)
   {
      Iterator j = i;
      while (j != begin && *j < *(j - 1))
      {
         swap(*j, *(j - 1));
         --j;
      }
   }
}

template <typename Iterator>
void counting_sort(Iterator begin, Iterator end)
{
   if (begin == end) return;  
   std::map<int, int> count;

   // Calculate the number of occurrences of each element
   for (Iterator i = begin; i != end; ++i) {
      count[*i]++;
   }

   // Offset the counts to get the cumulative counts
   auto it = count.begin();
   while (it != std::prev(count.end())) {
      std::next(it)->second += it->second;
      it++;
   }

   // Build the sorted array
   std::vector<int> sorted(end - begin);
   for (Iterator i = end - 1; i != begin - 1; --i) {
      sorted[--count[*i]] = *i;
   }

   // Copy the sorted array back to the original array
   copy(sorted.begin(), sorted.end(), begin);
}

