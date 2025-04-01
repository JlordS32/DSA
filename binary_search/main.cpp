#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
   if (end - begin <= 1)
   {
      return 0;
   }

   std::vector<int>::iterator mid = begin + ((end - begin) / 2);
   int profit = *std::max_element(mid, end) - *std::min_element(begin, mid);

   return std::max({maxProfit(begin, mid), maxProfit(mid, end), profit});
}

int main()
{
   std::vector<int> prices = {23, 5, 2, 64, 10, 1, 100, 23};
   
   std::cout << maxProfit(prices.begin(), prices.end()) << std::endl;

   return 0;
}