#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int singleNumber(const std::vector<int>& vec) {
    std::unordered_map<int, int> countMap;

    for (int num : vec) {
        countMap[num]++;
    }

    for (const auto& pair : countMap) {
        if (pair.second == 1) {
            return pair.first;
        }
    }

    return -1;
}