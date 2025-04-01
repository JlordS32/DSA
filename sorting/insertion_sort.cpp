#include <vector>

// void insertionSort(std::vector<T>& arr) {
//    int i, key, j;

//    for (int i = 1; i < arr.size(); i++) {
//       key = arr[i];
//       j = i - 1;

//       while (j >= 0 && arr[j] > key) {
//          arr[j + 1] = arr[j];
//          j--;
//       }

//       arr[j + 1] = key;
//    }
// };

void insertionSort(std::vector<int> &arr)
{
   for (std::size_t i = 1; i < arr.size(); i++)
   {
      while (i >= 1 && arr[i] < arr[i - 1])
      {
         std::swap(arr[i], arr[i - 1]);
         i--;
      }
   }
};