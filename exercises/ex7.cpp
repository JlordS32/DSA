#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>

// *** This is the function for you to complete
// you can assume that Iter is a random access iterator 
// and points to a value of type int
template <typename Iter>
int maxCrossing(Iter begin, Iter mid, Iter end) {
  int leftSum = std::numeric_limits<int>::min();
  int sum = 0;

  for (auto it = mid; it != begin;) {
    sum += *--it;
    leftSum = std::max(leftSum, sum);
  }

  int rightSum = std::numeric_limits<int>::min();
  sum = 0;
  for (auto it = mid; it != end; ++it) {
    sum += *it;
    rightSum = std::max(rightSum, sum);
  }

  return rightSum + leftSum;
}

// you can assume that Iter is a random access iterator 
// and points to a value of type int
template <typename Iter>
int maxSubarraySum(Iter begin, Iter end) {
  int n = std::distance(begin, end);
  // base case: if the interval is of size one there is 
  // only one (non-empty) sub-interval.  We return its sum.
  if (n == 1) {
    return *begin;
  }

  Iter mid = std::next(begin, n/2);
  // return the maximum value of the three cases
  return std::max({maxSubarraySum(begin, mid),
                   maxSubarraySum(mid, end),
                   maxCrossing(begin, mid, end)});
}