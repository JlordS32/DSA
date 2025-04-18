// tests/test_utils.hpp
#pragma once
#include <vector>
#include <random>
#include <algorithm>

inline std::vector<int> generate_random_vector(int size, int min_val, int max_val) {
   std::mt19937 rng(std::random_device{}());
   std::uniform_int_distribution<int> dist(min_val, max_val);
   std::vector<int> vec(size);
   std::generate(vec.begin(), vec.end(), [&]() { return dist(rng); });
   return vec;
}
