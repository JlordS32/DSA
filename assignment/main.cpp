#include <iostream>
#include "hash.cpp"

int main() {
   HashSet hs;

   hs.insert(10);
   hs.insert(20);
   hs.insert(14);
   hs.insert(12);

   for (auto it = hs.begin(); it != hs.end(); ++it) {
      std::cout << *it << std::endl;
   }

   std::cout << "Hello";

   return 0;
}