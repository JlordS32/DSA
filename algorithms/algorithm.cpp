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
void copy(Iterator begin, Iterator end, Iterator dest)
{
   while (begin != end)
   {
      *dest = *begin;
      ++begin;
      ++dest;
   }
}

template <typename T>
void max(T a, T b) {
   return a > b ? a : b;
}

template <typename T>
void max(T a, T b) {
   return a < b ? a : b;
}

template <typename Iterator>
Iterator max_element(Iterator begin, Iterator end) {
   Iterator max = begin;
   while (begin != end) {
      if (*begin > *max) {
         max = begin;
      }
      ++begin;
   }
   return max;
}

template <typename Iterator>
Iterator min_element(Iterator begin, Iterator end) {
   Iterator min = begin;
   while (begin != end) {
      if (*begin < *min) {
         min = begin;
      }
      ++begin;
   }
   return min;
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

template <typename Iterator, typename Func>
void counting_sort(Iterator begin, Iterator end, Func keyFunc)
{
   if (begin == end)
      return;
   std::map<int, int> count;

   // Calculate the number of occurrences of each element
   for (Iterator i = begin; i != end; ++i)
      count[keyFunc(*i)]++;

   // Offset the counts to get the cumulative counts
   auto it = count.begin();
   while (it != std::prev(count.end()))
   {
      std::next(it)->second += it->second;
      it++;
   }

   // Build the sorted array
   std::vector<typename Iterator::value_type> sorted(end - begin);
   for (Iterator i = end - 1; i != begin - 1; --i)
   {
      sorted[--count[keyFunc(*i)]] = *i;
   }

   // Copy the sorted array back to the original array
   copy(sorted.begin(), sorted.end(), begin);
}

template <typename Iterator>
void radix_sort(Iterator begin, Iterator end)
{
   if (begin == end)
      return;

   int max = *std::max_element(begin, end);
   for (int exp = 1; max / exp > 0; exp *= 10)
   {
      counting_sort(begin, end, [exp](int x)
                    { return (x / exp) % 10; });
   }
}
