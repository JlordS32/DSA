#include <vector>

void insertionSort(std::vector<int> & arr) {
   int n = arr.size();

   for (int i = 1; i < n; i++) {
      int key = arr[i];
      int j = i - 1;

      while (j >= 0 && arr[j] > key) {
         arr[j + 1] = arr[j];
         j--;
      }

      arr[j + 1] = key;
   }
}

// void insertionSort(std::vector<int> &arr)
// {
//    for (std::size_t i = 1; i < arr.size(); i++)
//    {
//       while (i >= 1 && arr[i] < arr[i - 1])
//       {
//          std::swap(arr[i], arr[i - 1]);
//          i--;
//       }
//    }
// };