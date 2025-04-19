#include <gtest/gtest.h>
#include "../algorithm.cpp"
#include "test_utils.hpp"

// ------------------------------
// INSERTION SORT TESTS
// ------------------------------

TEST(countingSort, randomArray)
{
   auto arr = generate_random_vector(10'000, -10'000, 10'000);
   auto expected = arr;
   std::sort(expected.begin(), expected.end());
   counting_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, expected);
}

TEST(countingSort, reversedArray)
{
   std::vector<int> arr(10'000);
   std::iota(arr.rbegin(), arr.rend(), 1); // fills with 1000..1
   counting_sort(arr.begin(), arr.end());

   std::vector<int> expected(10'000);
   std::iota(expected.begin(), expected.end(), 1); // 1..1000

   EXPECT_EQ(arr, expected);
}

TEST(countingSort, alreadySorted)
{
   std::vector<int> arr(10'000);
   std::iota(arr.begin(), arr.end(), 1); // fills with 1000..1
   counting_sort(arr.begin(), arr.end());

   std::vector<int> expected(10'000);
   std::iota(expected.begin(), expected.end(), 1); // 1..1000

   EXPECT_EQ(arr, expected);
}

TEST(countingSort, allSame)
{
   std::vector<int> arr = {7, 7, 7, 7, 7};
   counting_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, (std::vector<int>{7, 7, 7, 7, 7}));
}

TEST(countingSort, negAndPos)
{
   std::vector<int> arr = {-3, 0, 2, -1, 5};
   counting_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, (std::vector<int>{-3, -1, 0, 2, 5}));
}

TEST(countingSort, singleElement)
{
   std::vector<int> arr = {42};
   counting_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, (std::vector<int>{42}));
}

TEST(countingSort, emptyArray)
{
   std::vector<int> arr = {};
   counting_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, (std::vector<int>{}));
}