#include <gtest/gtest.h> 
#include "algorithm.cpp"
#include <iostream>
#include <vector>

TEST(sorting, bubbleSort) {
   std::vector<int> arr = {5, 4, 3, 2, 1};
   bubble_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(sorting, insertionSort) {
   std::vector<int> arr = {5, 4, 3, 2, 1};
   insertion_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(sorting, coutingSort) {
   std::vector<int> arr = {5, 4, 3, 2, 1};
   counting_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5}));
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
