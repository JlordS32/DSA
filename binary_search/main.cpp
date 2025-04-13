#include <iostream>
#include <vector>
#include <algorithm>

using Iterator = std::vector<int>::iterator;

int maxProfit(Iterator begin, Iterator end)
{
   if (end - begin <= 1)
   {
      return 0;
   }

   Iterator mid = begin + ((end - begin) / 2);
   int profit = *std::max_element(mid, end) - *std::min_element(begin, mid);

   return std::max({maxProfit(begin, mid), maxProfit(mid, end), profit});
}

int binarySearch(Iterator begin, Iterator end, int target) {
   if (begin >= end) return -1;
   Iterator mid = begin + ((end - begin) / 2);

   if (*mid == target) return *mid;
   else if (*mid > target) return binarySearch(begin, mid, target);
   else return binarySearch(mid + 1, end, target);
}

int main()
{
   std::vector<int> prices = {23, 5, 2, 64, 10, 1, 100, 23};
   sort(prices.begin(), prices.end());
   
   std::cout << binarySearch(prices.begin(), prices.end(), 233) << std::endl;

   return 0;
}