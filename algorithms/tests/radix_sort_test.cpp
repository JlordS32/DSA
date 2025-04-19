#include <gtest/gtest.h>
#include "../algorithm.cpp"
#include "test_utils.hpp"

// ------------------------------
// RADIX SORT TESTS
// ------------------------------

TEST(radixSort, randomArray)
{
   auto arr = generate_random_vector(100'000, 0, 200'000);
   auto expected = arr;
   std::sort(expected.begin(), expected.end());
   radix_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, expected);
}

TEST(radixSort, reversedArray)
{
   std::vector<int> arr(10'000);
   std::iota(arr.rbegin(), arr.rend(), 1); // fills with 1000..1
   radix_sort(arr.begin(), arr.end());

   std::vector<int> expected(10'000);
   std::iota(expected.begin(), expected.end(), 1); // 1..1000

   EXPECT_EQ(arr, expected);
}

TEST(radixSort, alreadySorted)
{
   std::vector<int> arr(10'000);
   std::iota(arr.begin(), arr.end(), 1); // fills with 1000..1
   radix_sort(arr.begin(), arr.end());

   std::vector<int> expected(10'000);
   std::iota(expected.begin(), expected.end(), 1); // 1..1000

   EXPECT_EQ(arr, expected);
}

TEST(radixSort, allSame)
{
   std::vector<int> arr = {7, 7, 7, 7, 7};
   radix_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, (std::vector<int>{7, 7, 7, 7, 7}));
}

TEST(radixSort, negAndPos)
{
   std::vector<int> arr = {-3, 0, 2, -1, 5};
   radix_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, (std::vector<int>{-3, -1, 0, 2, 5}));
}

TEST(radixSort, singleElement)
{
   std::vector<int> arr = {42};
   radix_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, (std::vector<int>{42}));
}

TEST(radixSort, emptyArray)
{
   std::vector<int> arr = {};
   radix_sort(arr.begin(), arr.end());
   EXPECT_EQ(arr, (std::vector<int>{}));
}