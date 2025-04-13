#include <iostream>
#include <queue>
#include <vector>
#include <functional>

int main()
{
   std::priority_queue<int, std::vector<int>, std::greater<int>> q;
   int k = 3;

   for (int i = 1; i <= 10; i++)
   {
      q.push(i);
      if (q.size() > k)
         q.pop();
   };

   std::cout << q.top() << std::endl;
   std::cout << q.size() << std::endl;

   return 0;
}