#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "hash.cpp"
#include <random>

// TEST(Level2Test, iteratorsValidAfterRehash)
// {
//    HashSet h;
//    h.maxLoadFactor(1.0);
//    std::vector<int> values{0, 13, 26, 39, 52, 65};
//    for (int x : values)
//    {
//       h.insert(x);
//    }
//    auto it = h.find(26);
//    ASSERT_EQ(*it, 26);
//    for (int i = 0; i < 100; ++i)
//    {
//       h.insert(i);
//    }
//    ASSERT_EQ(*it, 26);
// }

// TEST(Level1Test, setLoadFactorProvokesRehash)
// {
//    HashSet h;
//    ASSERT_TRUE(h.empty());
//    float threshold = 1.0;
//    h.maxLoadFactor(threshold);
//    std::mt19937 mt{89'338'157};
//    std::uniform_int_distribution<int> dist{-10'000, 10'000};
//    for (int i = 0; i < 1'000; i++)
//    {
//       int elem = dist(mt);
//       h.insert(elem);
//    }
//    ASSERT_FALSE(h.empty());
//    std::size_t initialSize = h.size();
//    threshold = 0.5;
//    h.maxLoadFactor(threshold);
//    ASSERT_GE(h.bucketCount(), 2 * initialSize);
// }

TEST(CollisionTest, SameBucketIndex) {
   HashSet hs;
   // Set a high max load factor so that rehashing doesn't occur during this test.
   hs.maxLoadFactor(1);
   hs.insert(13);
   hs.insert(26);
   // Since 13 % bucketCount == 26 % bucketCount for a bucketCount like 13,
   // they should fall in the same bucket.
   ASSERT_EQ(hs.bucketSize(hs.bucket(13)), 2);
   ASSERT_EQ(hs.bucket(13), hs.bucket(26));
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}