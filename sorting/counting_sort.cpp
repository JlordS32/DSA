#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

void countingSort(std::vector<int> &arr)
{
   if (arr.empty()) return;
   std::map<int, int> count;

   // Find the number of occurrences of each element
   for (int x : arr)
   {
      count[x]++;
   }
   
   auto it = count.begin();
   while (it != std::prev(count.end())) {
      std::next(it)->second += it->second;
      it++;
   }

   std::vector<int> sorted(arr.size());
   for (int i = 0; i < sorted.size(); i++) {
      sorted[--count[arr[i]]] = arr[i];
   }

   arr = sorted;
}

int main() {
   std::vector v = {8, 2, 1, 9, 8, 1, 2, 5};
   for (int num : v) {
      std::cout << num << " ";
   } 

   std::cout << std::endl;

   countingSort(v);

   for (int num : v) {
      std::cout << num << " ";
   }

   return 0;

}