#include <iostream>
#include <vector>
#include <algorithm>
#include "insertion_sort.cpp"
#include <unordered_map>

int main()
{
   std::vector<int> vec = {8, 2, 1, 9, 8, 1, 2, 5};

   insertionSort(vec);

   for (int num : vec)
   {
      std::cout << num << " ";
   }

   return 0;
}