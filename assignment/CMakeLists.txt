cmake_minimum_required(VERSION 3.16)
project(MyGTest)

include_directories("C:/gtest/googletest/googletest/include")
link_directories("C:/gtest/googletest/build/lib")

add_executable(test main.cpp)

# ✅ Link static libraries
target_link_libraries(test gtest gtest_main pthread)
