#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int numberOfDistinctElements(const std::vector<int>& vec) {
  if (vec.size() <= 1) return vec.size();
  
  std::vector<int> vecCopy (vec.begin(), vec.end());
  std::sort(vecCopy.begin(), vecCopy.end());
  auto it = std::unique(vecCopy.begin(), vecCopy.end());
  vecCopy.erase(it, vecCopy.end());
  
  return vecCopy.size();
}
