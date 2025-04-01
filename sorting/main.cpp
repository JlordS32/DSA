#include <iostream>
#include <vector>
#include <algorithm>
#include "bubble_sort.cpp"
#include "insertion_sort.cpp"
#include "counting_sort.cpp"
#include <unordered_map>

int main()
{
   std::vector<int> vec = {8, 2, 1, 9, 8, 1, 2, 5};

   auto it = std::unique(vec.begin(), vec.end());

   vec.erase(it, vec.end());
   
   for (int num : vec)
   {
      std::cout << num << " ";
   }

   return 0;
}