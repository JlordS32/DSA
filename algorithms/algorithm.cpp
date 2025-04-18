#include "algorithm.hpp"

template <typename T>
void swap(T &a, T &b)
{
   T temp = a;
   a = b;
   b = temp;
}

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
