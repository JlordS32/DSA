# Hi there, welcome to this repo.

Treat this repo as more like a lab for DSA. Everything here is a prototype.
Some of the folders here, especially .\algorithms, contain my own implemention or copy
for copy library of C++.

To use the tests cases. Follow the below:

# Google Test Setup
Before proceeding, make sure to install **CMake**, at: https://cmake.org/download/

## Google Test Installation
We first need to create the installation directory, I recommend doing it at C: Drive.

```bash
git clone https://github.com/google/googletest.git C:\gtest\googletest
cd C:\gtest\googletest
```
### For MinGW (g++)

```bash
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
```
### For Clang:
```bash
cmake -S . -B build-clang -G "Ninja" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
cmake --build build-clang
```
That's pretty much for the setup.

## Workflow (Using in your project)
### Folder Structure

For existing projects, just make sure you have `CMakeLists.txt` and `test.cpp`

```css
your_project/
├── CMakeLists.txt
├── test.cpp
└── (other src files)
```

### `test.cpp` sample

```cpp
#include <gtest/gtest.h> // Very important, make sure to include

TEST(MyTest, AddsCorrectly) {
    EXPECT_EQ(2 + 2, 4);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

Check out this link: [Google Test Getting Started](https://google.github.io/googletest/primer.html), to learn how to use google test.

### `CMakeLists.txt` example

```cpp
cmake_minimum_required(VERSION 3.16)
project(MyGTestProject)

# Make sure this directs to the googletest folder installation, if it's different, just ensure it matches
include_directories("C:/gtest/googletest/googletest/include")
link_directories("C:/gtest/googletest/build/lib")

# The file executable containing the header #indlue <gtest/gtest.h> and 
# the tests.

# add_executable([Name it however you want] <Main file here || main.cpp>)
# Example:
add_executable(test_sample test.cpp)

# target_link_libraries([Same name as above] gtest gtest_main pthread)
# Example:
target_link_libraries(test_sample gtest gtest_main pthread)
```

### Build & Run

From your project folder:

```bash
# First-time setup or if you added/renamed files
cmake -S . -B build -G "MinGW Makefiles"

# Build the test binary
cmake --build build

# Run tests
.\build\test_sample.exe
```

### Add more Test

```cpp
add_executable(test_sample test.cpp other_tests.cpp)
```