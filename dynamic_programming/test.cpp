#include <gtest/gtest.h>
#include <iostream>
#include "fib.cpp"

// Test suite for recursiveFib
TEST(RecursiveFibTest, SmallInput)
{
   EXPECT_EQ(recursiveFib(0), 0);
   EXPECT_EQ(recursiveFib(1), 1);
}

TEST(RecursiveFibTest, MidInput)
{
   EXPECT_EQ(recursiveFib(10), 55);
}

TEST(RecursiveFibTest, LargeInput)
{
   EXPECT_EQ(recursiveFib(50), 12586269025);
}

// Test suite for iterativeFib
TEST(IterativeFibTest, SmallInput)
{
   EXPECT_EQ(iterativeFib(0), 0);
   EXPECT_EQ(iterativeFib(1), 1);
}

TEST(IterativeFibTest, MidInput)
{
   EXPECT_EQ(iterativeFib(10), 55);
}

TEST(IterativeFibTest, LargeInput)
{
   EXPECT_EQ(iterativeFib(50), 12586269025);
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}