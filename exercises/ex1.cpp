#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

// returns the second largest number in a vector of integers
// under the promise the vector has at least two elements
int secondLargest(const std::vector<int> &vec)
{
   // these are dummy lines to suppress compiler warnings.
   // delete these lines and write your solution here.
   int largest{0}, second{0};
   for (int i = 0; i < vec.size(); i++)
   {
      if (vec.at(i) > largest)
      {
         second = largest;
         largest = vec.at(i);
      }
      else if (vec.at(i) > second && vec.at(i) < largest)
      {
         second = vec.at(i);
      }
      else if (vec.at(i) == largest)
      {
         second = vec.at(i);
      }
   }
   return second;
}
