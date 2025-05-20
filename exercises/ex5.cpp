#include <algorithm>
#include <string>
#include <unordered_map>

std::size_t firstUniqueChar(const std::string& inputString) {
  std::unordered_map<char, int> map;
  for (char c : inputString) {
    map[c]++;
  }

  for (int i = 0; i < inputString.size(); i++) {
    if (map[inputString[i]] == 1) return i;
  }


  return inputString.length();
}
