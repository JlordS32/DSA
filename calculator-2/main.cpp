#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "calc.cpp"

TEST(Calc, addTwoNumbers) {
  std::string input {"3 + 5"};
  EXPECT_EQ(Calc::eval(input), 8);
}

// write your own test cases to demonstrate the 
// added functionality

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
