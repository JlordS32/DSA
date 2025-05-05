#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename Iterator>
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

template <typename Iterator>
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
   std::list<int> prices2 = {23, 5, 2, 64, 10, 1, 100, 23};
   sort(prices.begin(), prices.end());
   
   std::cout << binarySearch(prices2.begin(), prices2.end(), 233) << std::endl;

   return 0;
}