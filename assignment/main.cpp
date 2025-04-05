#include <iostream>
#include <vector>
#include <chrono>
#include <cassert>
#include "hash.cpp"

int main()
{
   auto start = std::chrono::high_resolution_clock::now();

   HashSet hs;
   // Set a low max load factor to force rehashing sooner.
   
   // Insert enough elements to trigger a rehash.
   for (int i = 0; i < 50; ++i)
   {
      hs.insert(i);
   }
   
   // Verify that all elements are still present.
   for (int i = 0; i < 50; ++i)
   {
      assert(hs.contains(i));
   }
   
   for (int x : hs) {
      std::cout << x << " ";
   }
   
   auto end = std::chrono::high_resolution_clock::now();
   auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

   std::cout << "\n\nTime taken: " << duration.count() << " ms\n";
   return 0;
}