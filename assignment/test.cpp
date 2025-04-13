#include <iostream>
#include "hash.cpp"

int main()
{
   HashSet h;

   std::cout << "Inserting initial elements...\n";
   h.insert(13);
   h.insert(26);
   h.insert(39);

   std::cout << "Elements before rehash:\n";
   for (auto it = h.begin(); it != h.end(); ++it)
      std::cout << *it << " ";
   std::cout << "\n";

   std::cout << "Triggering rehash by inserting more...\n";
   h.insert(1);
   h.insert(2);
   h.insert(3); // Should trigger rehash here depending on initial size/loadFactor

   std::cout << "Elements after rehash:\n";
   for (auto it = h.begin(); it != h.end(); ++it)
      std::cout << *it << " ";
   std::cout << "\n";

   return 0;
}
