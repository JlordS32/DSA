#include <iostream>
#include <vector>

void swap(int& a, int& b) {
   int temp = a;
   a = b;
   b = temp;
}

template <typename T>
void bubbleSort(std::vector<T>& arr) {
   for (int i = 0; i < arr.size() - 1; i++) {
      for (int j = 0; j < arr.size() - i - 1; j++) {
         if (arr.at(j) > arr.at(j + 1)) {
            swap(arr.at(j), arr.at(j + 1));
         }
      }
   }
}

template <typename T>
void bubbleSort(T arr[]) {
   for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
      for (int j = 0; j < sizeof(arr) / sizeof(arr[0]) - i - 1; j++) {
         if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
         }
      }
   }
}

int main()
{
   std::vector<int> nums = {2, 3, 5, 102, 53};
   bubbleSort(nums);

   for (int x : nums) {
      std::cout << x << " ";
   }

   return 0;
}