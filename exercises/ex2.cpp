#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

// When the input vector is of size n 
// you are guaranteed that it contains all 
// of the integers 0, 1, 2, ..., n except for one.
// The goal of whoIsMissing is to return the missing number
int whoIsMissing(const std::vector<int>& vec) {
  // std::ignore = vec;
  std::vector<int> copyVec(vec.begin(), vec.end());
  std::sort(copyVec.begin(), copyVec.end());

  int counter = 0;
  for (int num : copyVec) {
    if (num != counter) return counter;
    counter++; 
  }

  return counter;
}