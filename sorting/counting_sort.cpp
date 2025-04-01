#include <vector>
#include <algorithm>
#include <map>

// void countingSort(std::vector<int> &arr)
// {
//    if (arr.empty())
//       return;

//    int max = *std::max_element(arr.begin(), arr.end());
//    int min = *std::min_element(arr.begin(), arr.end());

//    std::vector<int> count(max - min + 1, 0);

//    for (int x : arr)
//    {
//       count[x - min]++;
//    }

//    int index = 0;
//    for (int i = 0; i <= count.size(); i++)
//    {
//       while (count[i] > 0)
//       {
//          arr[index++] = i + min;
//          count[i]--;
//       }
//    }
// };

void countingSort(std::vector<int> &arr)
{
   if (arr.empty()) return;
   std::map<int, int> count;

   // Find the number of occurrences of each element
   for (int x : arr)
   {
      count[x]++;
   }
   
   auto prev = count.begin(); // Starting element
   auto it = std::next(prev); // Next element

   while (it != count.end()) {
      it->second += prev->second;
      
      // Point to next
      prev++;
      it++;
   }

   std::vector<int> sorted(arr.size());
   for (int i = arr.size() - 1; i >= 0; i--) {
      sorted[count[arr[i]] - 1] = arr[i];
      count[arr[i]]--;
   }

   arr = sorted;
}