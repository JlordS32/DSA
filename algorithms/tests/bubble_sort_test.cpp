#include <gtest/gtest.h>
#include "../algorithm.cpp"
#include "test_utils.hpp"

// ------------------------------
// BUBBLE SORT TESTS
// ------------------------------

TEST(bubbleSort, randomArray)
{
   auto arr = generate_random_vector(10'000, -10'000, 10'000);
   auto expected = arr;
   std::sort(expected.begin(), expected.end());
   bubble_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, expected);
}

TEST(bubbleSort, reversedArray)
{
   std::vector<int> arr(10'000);
   std::iota(arr.rbegin(), arr.rend(), 1); // fills with 1000..1
   bubble_sort(arr.begin(), arr.end());

   std::vector<int> expected(10'000);
   std::iota(expected.begin(), expected.end(), 1); // 1..1000

   EXPECT_EQ(arr, expected);
}

TEST(bubbleSort, alreadySorted)
{
   std::vector<int> arr(10'000);
   std::iota(arr.begin(), arr.end(), 1); // fills with 1000..1
   bubble_sort(arr.begin(), arr.end());

   std::vector<int> expected(10'000);
   std::iota(expected.begin(), expected.end(), 1); // 1..1000

   EXPECT_EQ(arr, expected);
}

TEST(bubbleSort, allSame)
{
   std::vector<int> arr = {7, 7, 7, 7, 7};
   bubble_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, (std::vector<int>{7, 7, 7, 7, 7}));
}

TEST(bubbleSort, negAndPos)
{
   std::vector<int> arr = {-3, 0, 2, -1, 5};
   bubble_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, (std::vector<int>{-3, -1, 0, 2, 5}));
}

TEST(bubbleSort, singleElement)
{
   std::vector<int> arr = {42};
   bubble_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, (std::vector<int>{42}));
}

TEST(bubbleSort, emptyArray)
{
   std::vector<int> arr = {};
   bubble_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, (std::vector<int>{}));
}