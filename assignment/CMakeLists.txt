cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project(MyGTest)

include_directories("C:/gtest/googletest/googletest/include")
link_directories("C:/gtest/googletest/build/lib")

add_executable(test main.cpp)

# ✅ Link static libraries
target_link_libraries(test gtest gtest_main pthread)
