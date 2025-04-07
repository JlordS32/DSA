#include <iostream>
#include <vector>

using Iterator = std::vector<int>::iterator;

void merge(Iterator begin, Iterator mid, Iterator end) {
   std::vector<int> temp;
   auto left = begin, right = mid;

   while (left != mid && right != end) {
      if (*left < *right) {
         temp.push_back(*left);
         left++;
      } else {
         temp.push_back(*right);
         right++;
      }
   }

   while (left != mid) {
      temp.push_back(*left);
      left++;
   }

   while (right != end) {
      temp.push_back(*right);
      right++;
   }

   std::copy(temp.begin(), temp.end(), begin);
}

void mergeSort(Iterator begin, Iterator end) {
   if (end - begin <= 1) {
      return;
   }

   Iterator mid = begin + ((end - begin) / 2);
   mergeSort(begin, mid);
   mergeSort(mid, end);
   merge(begin, mid, end);
}

int main() {
   std::vector<int> vec = {8, 2, 1, 9, 8, 1, 2, 5};

   mergeSort(vec.begin(), vec.end());

   for (int num : vec) {
      std::cout << num << " ";
   }

   return 0;
}