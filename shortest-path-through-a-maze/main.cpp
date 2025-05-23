#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <queue>
#include <map>
#include "maze_solver.hpp"
#include "point.hpp"

TEST(mazeSolver, ex1) {
  std::vector<std::string> maze = {
    "   #       ",
    "## # ##### ",
    " # #   #   ",
    " # ### # ##",
    "   #   #   ",
    " ### ##### ",
    "   #     # ",
    "## ####### ",
    " #         ",
    " ######### ",
    "           "};
  std::vector<std::string> solution = {
    "   #.......",
    "## # #####.",
    " #.#   #...",
    " #.### #.##",
    "...#   #...",
    ".### #####.",
    "...#     #.",
    "##.#######.",
    " #.........",
    " ######### ",
    "           "};
  EXPECT_EQ(solveMaze(maze, {0, 4}, {2, 2}), solution); 
}

TEST(mazeSolver, ex2) {
  std::vector<std::string> maze = {
    "   #       ",
    "## # # ### ",
    " # # #   # ",
    " # ##### # ",
    " #   #   # ",
    " ### # ####",
    "   # #     ",
    " ### # ### ",
    "   # # #   ",
    " # # ### # ",
    " #       # "};
  std::vector<std::string> solution = {
    "...#  .    ",
    "##.# #.### ",
    " #.# #...# ",
    " #.#####.# ",
    " #...#...# ",
    " ###.#.####",
    "   #.#.....",
    " ###.# ###.",
    "   #.# #...",
    " # #.###.# ",
    " #  .....# "};
  EXPECT_EQ(solveMaze(maze, {0, 6}, {0, 0}), solution);
}

TEST(mazeSolver, ex3) {
  std::vector<std::string> maze = {
    "   #     # ",
    "## # # # # ",
    "   # # # # ",
    " ##### # # ",
    "     # #   ",
    "#### # ####",
    "   # #     ",
    "## # ### # ",
    "   #   # # ",
    " ##### ### ",
    "           "};
  std::vector<std::string> solution = {
    "...#  ...# ",
    "##.# #.# # ",
    "...# #.# # ",
    ".#####.# # ",
    ".....#.#   ",
    "####.#.####",
    "   #.#.....",
    "## #.### #.",
    "   #...# #.",
    " #####.###.",
    "      ....."};
  EXPECT_EQ(solveMaze(maze, {0, 0}, {0, 8}), solution);
}

TEST(mazeSolver, ex4) {
  std::vector<std::string> maze = {
    "   #     # ",
    "## # # # # ",
    "   # # # # ",
    " ##### # # ",
    "     # #   ",
    "#### # ####",
    "   # #     ",
    "## # ### # ",
    "   #   # # ",
    " ##### ### ",
    "           "};
  std::vector<std::string> solution = {
    "   #     # ",
    "## # # # # ",
    "...# # # # ",
    ".##### # # ",
    ".....# #   ",
    "####.# ####",
    "   #.#  ...",
    "## #.###.#.",
    "   #...#.#.",
    " #####.###.",
    "      ....."};
  EXPECT_EQ(solveMaze(maze, {8, 8}, {2, 2}), solution);
}

TEST(mazeSolver, ex5) {
  std::vector<std::string> maze = {
    "   #       #       # ",
    "## ### ### ##### # # ",
    " #   #   # #     # # ",
    " ### # # # # ##### # ",
    "   # # # #   #   # # ",
    "## # # # ##### ### # ",
    "   # # #     #   #   ",
    " # # ### ### ### ### ",
    " # #   # #   #   #   ",
    " # ### # # ### # # ##",
    " # #   # #   # # # # ",
    " ### ### ### # ### # ",
    "   # # # #   # #   # ",
    " # # # # # ### # ### ",
    " # # #   #   # # #   ",
    " # # ####### # # # ##",
    " # #       # #   #   ",
    "## ####### # # ##### ",
    "   #   #   # # #     ",
    " ### # # ### # ### # ",
    "     #       #     # ",};
  std::vector<std::string> solution = {
    "   #       #       # ",
    "## ### ### ##### # # ",
    " #   #   # #     # # ",
    " ### # # # # ##### # ",
    "   # # # #   #   # # ",
    "## # # # ##### ### # ",
    "   # # #.....#   #   ",
    " # # ###.###.### ### ",
    " # #  .#.#...#   #   ",
    " # ###.# #.### # # ##",
    " # #...# #...# # # # ",
    " ###.### ###.# ### # ",
    "   #.# # #...# #   # ",
    " # #.# # #.### # ### ",
    " # #.#   #...# # #   ",
    " # #.#######.# # # ##",
    " # #.......#.#   #   ",
    "## #######.#.# ##### ",
    "   #   #...#.# #     ",
    " ### # #.###.# ### # ",
    "     #  .....#     # ",};
  EXPECT_EQ(solveMaze(maze, {8, 6}, {8, 8}), solution);
}

TEST(mazeSolver, ex6) {
  std::vector<std::string> maze = {
    "     #     #       # ",
    "#### ### # ### ### # ",
    "   # #   #     # #   ",
    " # # # ######### ### ",
    " # # # #     #       ",
    " ### # # ##### ######",
    "   #   #     # #     ",
    " # ##### ### # ##### ",
    " #     #   #   #   # ",
    " ### # ### ##### # # ",
    " # # # #   #     # # ",
    " # # ### ####### # # ",
    " # #   #         # # ",
    " # ### ########### # ",
    " # #       #     #   ",
    " # # ####### # ##### ",
    "   #     #   #     # ",
    " ####### # ####### # ",
    " #       #   #     # ",
    " # ######### # ##### ",
    " #           #       ",};
  std::vector<std::string> solution = {
    "     #  ...#  .....# ",
    "#### ###.#.###.###.# ",
    "   # #  .#.....# #...",
    " # # # ######### ###.",
    " # # # #     #.......",
    " ### # # #####.######",
    "   #   #.....#.#     ",
    " # #####.###.#.##### ",
    " #  ...#...#...#...# ",
    " ###.#.###.#####.#.# ",
    " # #.#.#...#    .#.# ",
    " # #.###.#######.#.# ",
    " # #...#.........#.# ",
    " # ###.###########.# ",
    " # #...    #...  #...",
    " # #.#######.#.#####.",
    "   #.....#...#.....#.",
    " #######.#.#######.#.",
    " #.......#...#.....#.",
    " #.#########.#.#####.",
    " #...........#.......",};
  EXPECT_EQ(solveMaze(maze, {10, 6}, {2, 8}), solution);
}

TEST(mazeSolver, ex7) {
  std::vector<std::string> maze = {
    "     #     #       # ",
    "#### ##### # ### # # ",
    "   # #     # #   #   ",
    " ### # ##### # ##### ",
    " #   #       #     # ",
    " # ########### ### # ",
    "   #     #   #   # # ",
    " ##### # # # ##### # ",
    " #     #   # #     # ",
    " ### ####### # ##### ",
    "   #     # # # #   # ",
    "## # ### # # # ### # ",
    " # # #   # #   #   # ",
    " # ### ### ##### # # ",
    "   #   #         # # ",
    " ### ### ####### # # ",
    " #   #   #     # # # ",
    " ### # ####### # ### ",
    "     # #     # #   # ",
    "###### # ### # ### # ",
    "         #       #   ",};
  std::vector<std::string> solution = {
    "     #     #       # ",
    "#### ##### # ### # # ",
    "   # #     # #   #   ",
    " ### # ##### # ##### ",
    " #   #       #     # ",
    " # ########### ### # ",
    "   #  ...#...#   # # ",
    " #####.#.#.#.##### # ",
    " #  ...#...#.#     # ",
    " ###.#######.# ##### ",
    "   #.....# #.# #   # ",
    "## # ###.# # # ### # ",
    " # # #...# #   #   # ",
    " # ###.### ##### # # ",
    "   #...#         # # ",
    " ###.### ####### # # ",
    " #  .#   #     # # # ",
    " ### # ####### # ### ",
    "     # #     # #   # ",
    "###### # ### # ### # ",
    "         #       #   ",};
  EXPECT_EQ(solveMaze(maze, {10, 12}, {16, 4}), solution);
}

TEST(mazeSolver, ex8) {
  std::vector<std::string> maze = {
    "     #     #       # ",
    "#### ##### # ### # # ",
    "   # #     # #   #   ",
    " ### # ##### # ##### ",
    " #   #       #     # ",
    " # ########### ### # ",
    "   #     #   #   # # ",
    " ##### # # # ##### # ",
    " #     #   # #     # ",
    " ### ####### # ##### ",
    "   #     # # # #   # ",
    "## # ### # # # ### # ",
    " # # #   # #   #   # ",
    " # ### ### ##### # # ",
    "   #   #         # # ",
    " ### ### ####### # # ",
    " #   #   #     # # # ",
    " ### # ####### # ### ",
    "     # #     # #   # ",
    "###### # ### # ### # ",
    "         #       #   ",};
  std::vector<std::string> solution = {
    "  ...#     #    ...# ",
    "####.##### # ###.#.# ",
    "   #.#     # #...#...",
    " ###.# ##### #.#####.",
    " #...#       #.....#.",
    " #.########### ###.#.",
    "...#  ...#...#   #.#.",
    ".#####.#.#.#.#####.#.",
    ".#  ...#...#.#.....#.",
    ".###.#######.#.#####.",
    "...#.....# #.#.#...#.",
    "##.# ###.# #.#.###.#.",
    " #.# #...# #...#...#.",
    " #.###.### #####.# #.",
    "...#...#        .# #.",
    ".###.### #######.# #.",
    ".#  .#   #     #.# #.",
    ".###.# ####### #.###.",
    ".....# #     # #...#.",
    "###### # ### # ###.#.",
    "         #       #...",};
  EXPECT_EQ(solveMaze(maze, {10, 16}, {0, 2}), solution);
}

TEST(mazeSolver, ex9) {
  std::vector<std::string> maze = {
    "     #     #       # ",
    "#### ##### # ### # # ",
    "   # #     # #   #   ",
    " ### # ##### # ##### ",
    " #   #       #     # ",
    " # ########### ### # ",
    "   #     #   #   # # ",
    " ##### # # # ##### # ",
    " #     #   # #     # ",
    " ### ####### # ##### ",
    "   #     # # # #   # ",
    "## # ### # # # ### # ",
    " # # #   # #   #   # ",
    " # ### ### ##### # # ",
    "   #   #         # # ",
    " ### ### ####### # # ",
    " #   #   #     # # # ",
    " ### # ####### # ### ",
    "     # #     # #   # ",
    "###### # ### # ### # ",
    "         #       #   ",};
  std::vector<std::string> solution = {
    "    .#     #    ...# ",
    "####.##### # ###.#.# ",
    "   #.#     # #...#...",
    " ###.# ##### #.#####.",
    " #...#       #.....#.",
    " #.########### ###.#.",
    "...#  ...#...#   #.#.",
    ".#####.#.#.#.#####.#.",
    ".#  ...#...#.#.....#.",
    ".###.#######.#.#####.",
    "...#.....# #.#.#   #.",
    "##.# ###.# #.#.### #.",
    " #.# #...# #...#   #.",
    " #.###.### ##### # #.",
    "...#...#.........# #.",
    ".###.###.#######.# #.",
    ".#  .#...#  ...#.# #.",
    ".###.#.#######.#.###.",
    ".....#.#.....#.#...#.",
    "######.#.###.#.###.#.",
    "      ...#  ...  #...",};
  EXPECT_EQ(solveMaze(maze, {0, 4}, {16, 12}), solution);
}

TEST(mazeSolver, ex10) {
  std::vector<std::string> maze = {
    "     #     #       # ",
    "#### ##### # ### # # ",
    "   # #     # #   #   ",
    " ### # ##### # ##### ",
    " #   #       #     # ",
    " # ########### ### # ",
    "   #     #   #   # # ",
    " ##### # # # ##### # ",
    " #     #   # #     # ",
    " ### ####### # ##### ",
    "   #     # # # #   # ",
    "## # ### # # # ### # ",
    " # # #   # #   #   # ",
    " # ### ### ##### # # ",
    "   #   #         # # ",
    " ### ### ####### # # ",
    " #   #   #     # # # ",
    " ### # ####### # ### ",
    "     # #     # #   # ",
    "###### # ### # ### # ",
    "         #       #   ",};
  std::vector<std::string> solution = {
    "     #     #       # ",
    "#### ##### # ### # # ",
    "   # #     # #   #   ",
    " ### # ##### # ##### ",
    " #   #       #     # ",
    " # ########### ### # ",
    "   #     #   #   # #.",
    " ##### # # # ##### #.",
    " #     #   # #     #.",
    " ### ####### # #####.",
    "   #     # # # #   #.",
    "## # ### # # # ### #.",
    " # # #   # #   #   #.",
    " # ### ### ##### # #.",
    "   #   #        .# #.",
    " ### ### #######.# #.",
    " #   #   #     #.# #.",
    " ### # ####### #.###.",
    "     # #     # #...#.",
    "###### # ### # ###.#.",
    "         #       #...",};
  EXPECT_EQ(solveMaze(maze, {14, 16}, {6, 20}), solution);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
