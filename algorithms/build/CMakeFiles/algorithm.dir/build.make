# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\build

# Include any dependencies generated for this target.
include CMakeFiles/algorithm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/algorithm.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/algorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algorithm.dir/flags.make

CMakeFiles/algorithm.dir/codegen:
.PHONY : CMakeFiles/algorithm.dir/codegen

CMakeFiles/algorithm.dir/tests/bubble_sort_test.cpp.obj: CMakeFiles/algorithm.dir/flags.make
CMakeFiles/algorithm.dir/tests/bubble_sort_test.cpp.obj: CMakeFiles/algorithm.dir/includes_CXX.rsp
CMakeFiles/algorithm.dir/tests/bubble_sort_test.cpp.obj: C:/Users/jlord/OneDrive/Documents/Programming/DSA/algorithms/tests/bubble_sort_test.cpp
CMakeFiles/algorithm.dir/tests/bubble_sort_test.cpp.obj: CMakeFiles/algorithm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/algorithm.dir/tests/bubble_sort_test.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/algorithm.dir/tests/bubble_sort_test.cpp.obj -MF CMakeFiles\algorithm.dir\tests\bubble_sort_test.cpp.obj.d -o CMakeFiles\algorithm.dir\tests\bubble_sort_test.cpp.obj -c C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\tests\bubble_sort_test.cpp

CMakeFiles/algorithm.dir/tests/bubble_sort_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/algorithm.dir/tests/bubble_sort_test.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\tests\bubble_sort_test.cpp > CMakeFiles\algorithm.dir\tests\bubble_sort_test.cpp.i

CMakeFiles/algorithm.dir/tests/bubble_sort_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/algorithm.dir/tests/bubble_sort_test.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\tests\bubble_sort_test.cpp -o CMakeFiles\algorithm.dir\tests\bubble_sort_test.cpp.s

CMakeFiles/algorithm.dir/tests/insertion_sort_test.cpp.obj: CMakeFiles/algorithm.dir/flags.make
CMakeFiles/algorithm.dir/tests/insertion_sort_test.cpp.obj: CMakeFiles/algorithm.dir/includes_CXX.rsp
CMakeFiles/algorithm.dir/tests/insertion_sort_test.cpp.obj: C:/Users/jlord/OneDrive/Documents/Programming/DSA/algorithms/tests/insertion_sort_test.cpp
CMakeFiles/algorithm.dir/tests/insertion_sort_test.cpp.obj: CMakeFiles/algorithm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/algorithm.dir/tests/insertion_sort_test.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/algorithm.dir/tests/insertion_sort_test.cpp.obj -MF CMakeFiles\algorithm.dir\tests\insertion_sort_test.cpp.obj.d -o CMakeFiles\algorithm.dir\tests\insertion_sort_test.cpp.obj -c C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\tests\insertion_sort_test.cpp

CMakeFiles/algorithm.dir/tests/insertion_sort_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/algorithm.dir/tests/insertion_sort_test.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\tests\insertion_sort_test.cpp > CMakeFiles\algorithm.dir\tests\insertion_sort_test.cpp.i

CMakeFiles/algorithm.dir/tests/insertion_sort_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/algorithm.dir/tests/insertion_sort_test.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\tests\insertion_sort_test.cpp -o CMakeFiles\algorithm.dir\tests\insertion_sort_test.cpp.s

CMakeFiles/algorithm.dir/tests/counting_sort_test.cpp.obj: CMakeFiles/algorithm.dir/flags.make
CMakeFiles/algorithm.dir/tests/counting_sort_test.cpp.obj: CMakeFiles/algorithm.dir/includes_CXX.rsp
CMakeFiles/algorithm.dir/tests/counting_sort_test.cpp.obj: C:/Users/jlord/OneDrive/Documents/Programming/DSA/algorithms/tests/counting_sort_test.cpp
CMakeFiles/algorithm.dir/tests/counting_sort_test.cpp.obj: CMakeFiles/algorithm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/algorithm.dir/tests/counting_sort_test.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/algorithm.dir/tests/counting_sort_test.cpp.obj -MF CMakeFiles\algorithm.dir\tests\counting_sort_test.cpp.obj.d -o CMakeFiles\algorithm.dir\tests\counting_sort_test.cpp.obj -c C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\tests\counting_sort_test.cpp

CMakeFiles/algorithm.dir/tests/counting_sort_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/algorithm.dir/tests/counting_sort_test.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\tests\counting_sort_test.cpp > CMakeFiles\algorithm.dir\tests\counting_sort_test.cpp.i

CMakeFiles/algorithm.dir/tests/counting_sort_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/algorithm.dir/tests/counting_sort_test.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\tests\counting_sort_test.cpp -o CMakeFiles\algorithm.dir\tests\counting_sort_test.cpp.s

CMakeFiles/algorithm.dir/tests/radix_sort_test.cpp.obj: CMakeFiles/algorithm.dir/flags.make
CMakeFiles/algorithm.dir/tests/radix_sort_test.cpp.obj: CMakeFiles/algorithm.dir/includes_CXX.rsp
CMakeFiles/algorithm.dir/tests/radix_sort_test.cpp.obj: C:/Users/jlord/OneDrive/Documents/Programming/DSA/algorithms/tests/radix_sort_test.cpp
CMakeFiles/algorithm.dir/tests/radix_sort_test.cpp.obj: CMakeFiles/algorithm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/algorithm.dir/tests/radix_sort_test.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/algorithm.dir/tests/radix_sort_test.cpp.obj -MF CMakeFiles\algorithm.dir\tests\radix_sort_test.cpp.obj.d -o CMakeFiles\algorithm.dir\tests\radix_sort_test.cpp.obj -c C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\tests\radix_sort_test.cpp

CMakeFiles/algorithm.dir/tests/radix_sort_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/algorithm.dir/tests/radix_sort_test.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\tests\radix_sort_test.cpp > CMakeFiles\algorithm.dir\tests\radix_sort_test.cpp.i

CMakeFiles/algorithm.dir/tests/radix_sort_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/algorithm.dir/tests/radix_sort_test.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\tests\radix_sort_test.cpp -o CMakeFiles\algorithm.dir\tests\radix_sort_test.cpp.s

CMakeFiles/algorithm.dir/tests/test_main.cpp.obj: CMakeFiles/algorithm.dir/flags.make
CMakeFiles/algorithm.dir/tests/test_main.cpp.obj: CMakeFiles/algorithm.dir/includes_CXX.rsp
CMakeFiles/algorithm.dir/tests/test_main.cpp.obj: C:/Users/jlord/OneDrive/Documents/Programming/DSA/algorithms/tests/test_main.cpp
CMakeFiles/algorithm.dir/tests/test_main.cpp.obj: CMakeFiles/algorithm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/algorithm.dir/tests/test_main.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/algorithm.dir/tests/test_main.cpp.obj -MF CMakeFiles\algorithm.dir\tests\test_main.cpp.obj.d -o CMakeFiles\algorithm.dir\tests\test_main.cpp.obj -c C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\tests\test_main.cpp

CMakeFiles/algorithm.dir/tests/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/algorithm.dir/tests/test_main.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\tests\test_main.cpp > CMakeFiles\algorithm.dir\tests\test_main.cpp.i

CMakeFiles/algorithm.dir/tests/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/algorithm.dir/tests/test_main.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\tests\test_main.cpp -o CMakeFiles\algorithm.dir\tests\test_main.cpp.s

# Object files for target algorithm
algorithm_OBJECTS = \
"CMakeFiles/algorithm.dir/tests/bubble_sort_test.cpp.obj" \
"CMakeFiles/algorithm.dir/tests/insertion_sort_test.cpp.obj" \
"CMakeFiles/algorithm.dir/tests/counting_sort_test.cpp.obj" \
"CMakeFiles/algorithm.dir/tests/radix_sort_test.cpp.obj" \
"CMakeFiles/algorithm.dir/tests/test_main.cpp.obj"

# External object files for target algorithm
algorithm_EXTERNAL_OBJECTS =

algorithm.exe: CMakeFiles/algorithm.dir/tests/bubble_sort_test.cpp.obj
algorithm.exe: CMakeFiles/algorithm.dir/tests/insertion_sort_test.cpp.obj
algorithm.exe: CMakeFiles/algorithm.dir/tests/counting_sort_test.cpp.obj
algorithm.exe: CMakeFiles/algorithm.dir/tests/radix_sort_test.cpp.obj
algorithm.exe: CMakeFiles/algorithm.dir/tests/test_main.cpp.obj
algorithm.exe: CMakeFiles/algorithm.dir/build.make
algorithm.exe: CMakeFiles/algorithm.dir/linkLibs.rsp
algorithm.exe: CMakeFiles/algorithm.dir/objects1.rsp
algorithm.exe: CMakeFiles/algorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable algorithm.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\algorithm.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algorithm.dir/build: algorithm.exe
.PHONY : CMakeFiles/algorithm.dir/build

CMakeFiles/algorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\algorithm.dir\cmake_clean.cmake
.PHONY : CMakeFiles/algorithm.dir/clean

CMakeFiles/algorithm.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\build C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\build C:\Users\jlord\OneDrive\Documents\Programming\DSA\algorithms\build\CMakeFiles\algorithm.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/algorithm.dir/depend

