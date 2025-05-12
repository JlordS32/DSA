#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

uint64_t recursiveFib(uint64_t n)
{
   if (n <= 1)
      return n;
   return recursiveFib(n - 1) + recursiveFib(n - 2);
}

uint64_t iterativeFib(uint64_t n)
{
   if (n <= 1)
      return n;

   uint64_t a = 0;
   uint64_t b = 1;
   uint64_t c = a + b;
   for (uint64_t i = 2; i < n; i++)
   {
      a = b;
      b = c;
      c = a + b;
   }
   return c;
}

uint64_t tabulationFib(uint64_t n)
{
   if (n <= 1)
      return n;

   uint64_t dp[n + 1];
   dp[0] = 0;
   dp[1] = 1;

   for (uint64_t i = 2; i <= n; i++)
   {
      dp[i] = dp[i - 1] + dp[i - 2];
   }

   return dp[n];
}

class LectureMemoFib
{
private:
   std::vector<int64_t> memo;
   int64_t fibHelper(int n);

public:
   int64_t compute(int n);
};

int64_t LectureMemoFib::fibHelper(int n)
{
   if (memo[n] >= 0)
      return memo[n];
   memo[n] = fibHelper(n - 1) + fibHelper(n - 2);
   return memo[n];
}

int64_t LectureMemoFib::compute(int n)
{
   if (n <= 1)
      return n;

   memo.resize(n + 1, -1);
   memo[0] = 0;
   memo[1] = 1;
   return fibHelper(n);
}