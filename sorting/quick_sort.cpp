#include <vector>
#include <iostream>
#include <algorithm> // for std::swap

using Iterator = std::vector<int>::iterator;

Iterator partition(Iterator begin, Iterator end)
{
   Iterator pivotIt = std::prev(end);
   Iterator leftEnd = begin;

   Iterator i = begin;
   while (i != pivotIt)
   {
      if (*i < *pivotIt)
      {
         std::swap(*i, *leftEnd);
         leftEnd++;
      }
      i++;
   }

   std::swap(*pivotIt, *leftEnd);
   return leftEnd;
}

void quickSort(Iterator begin, Iterator end)
{
   if (end - begin <= 1)
      return;

   // Get pivot
   Iterator pivot = partition(begin, end);

   // Recurse [begin, pivot) and [pivot + 1, end)
   quickSort(begin, pivot);
   quickSort(pivot + 1, end);
}

int main()
{
   std::vector<int> vec = {8, 2, 1, 9, 8, 1, 2, 5};

   quickSort(vec.begin(), vec.end());

   for (int num : vec)
   {
      std::cout << num << " ";
   }

   return 0;
}
