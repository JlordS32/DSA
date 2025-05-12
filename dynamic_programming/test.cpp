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
   EXPECT_EQ(recursiveFib(40), 102334155);
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
   EXPECT_EQ(iterativeFib(40), 102334155);
}

// Test suite for tabulationFib
TEST(tabulationFibTest, SmallInput)
{
   EXPECT_EQ(tabulationFib(0), 0);
   EXPECT_EQ(tabulationFib(1), 1);
}

TEST(tabulationFibTest, MidInput)
{
   EXPECT_EQ(tabulationFib(10), 55);
}

TEST(tabulationFibTest, LargeInput)
{
   EXPECT_EQ(tabulationFib(40), 102334155);
}

// Lecture test
TEST(LectureImplementation, SmallInput)
{
   LectureMemoFib fib;
   EXPECT_EQ(fib.compute(0), 0);
   EXPECT_EQ(fib.compute(1), 1);
}

TEST(LectureImplementation, MidInput)
{
   LectureMemoFib fib;
   EXPECT_EQ(fib.compute(10), 55);
}

TEST(LectureImplementation, LargeInput)
{
   LectureMemoFib fib;
   EXPECT_EQ(fib.compute(40), 102334155);
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}