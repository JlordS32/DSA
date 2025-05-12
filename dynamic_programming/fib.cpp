#pragma once 
#include <iostream>

uint64_t recursiveFib(uint64_t n) {
   if (n <= 1) return n;
   return recursiveFib(n - 1) + recursiveFib(n - 2);
}

uint64_t iterativeFib(uint64_t n) {
   if (n <= 1) return n;

   uint64_t a = 0;
   uint64_t b = 1;
   uint64_t c = a + b;
   for (uint64_t i = 2; i < n; i++) {
      a = b;
      b = c;
      c = a + b;
   }
   return c;
}