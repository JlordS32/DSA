#include <iostream>
#include <string>
#include <algorithm>

// given two strings, return true if and only if they contain 
// exactly the same letters including repetition.
bool sameLetters( const std::string& firstString, 
                  const std::string& secondString) {
  std::string t = firstString;
  std::string s = secondString;

  std::sort(s.begin(), s.end());
  std::sort(t.begin(), t.end());

  return s == t;
}
