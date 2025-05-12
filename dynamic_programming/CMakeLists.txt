cmake_minimum_required(VERSION 3.16)
project(MyGTestProject)

# Make sure this directs to the googletest folder installation, if it's different, just ensure it matches
include_directories("C:/gtest/googletest/googletest/include")
link_directories("C:/gtest/googletest/build/lib")

# The file executable containing the header #indlue <gtest/gtest.h> and 
# the tests.

# add_executable([Name it however you want] <Main file here || main.cpp>)
# Example:
add_executable(test ./fib/test.cpp)

# target_link_libraries([Same name as above] gtest gtest_main pthread)
# Example:
target_link_libraries(test gtest gtest_main pthread)