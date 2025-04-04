#include <iostream>
#include <vector>
#include "hash.cpp"

int main() {
   HashSet hs;
   
   std::vector<int> repeatedNumbers {5, 32, 5, -20, -20, 32, 5};

   for (int x : repeatedNumbers) {
      hs.insert(x);
   }
   std::cout << hs.size();

   return 0;
}