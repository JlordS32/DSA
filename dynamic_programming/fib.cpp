#pragma once 
#include <iostream>

int recursiveFib(int n) {
   if (n <= 1) return n;
   return recursiveFib(n - 1) + recursiveFib(n - 2);
}

int iterativeFib(int n) {
   if (n <= 1) return n;

   int a = 0;
   int b = 1;
   int c = a + b;
   for (int i = 2; i < n; i++) {
      a = b;
      b = c;
      c = a + b;
   }
   return c;
}