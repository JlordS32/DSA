#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

struct Point {
  int row {};
  int col {};
};

// determine if two points are equal
bool operator==(const Point& x, const Point& y);

// determine if two points are different
bool operator!=(const Point& x, const Point& y);

// add two points together
Point operator+(const Point& x, const Point& y);

bool isEdge(const std::vector<std::string>&, const Point&, const Point&);

// operations on points
bool operator==(const Point& x, const Point& y) {
  return x.row == y.row and x.col == y.col;
}

bool operator!=(const Point& x, const Point& y) {
  return not (x == y);
}

Point operator+(const Point& x, const Point& y) {
  return Point {x.row + y.row, x.col + y.col};
}

// given a maze (where # denotes walls) is there an edge between Point x 
// and Point y?  For this to be true x and y have to be represent valid 
// indices into the maze, maze at these points should not be a wall, and
// y has to be one square left, up, down, or right from x
bool isEdge(const std::vector<std::string>& maze, const Point& x, const Point& y) {
  // Check self loop
  if (x == y) return false;

  // Check adjacency
  if (!(std::abs(x.row - y.row) == 1 && x.col == y.col || 
          std::abs(x.col - y.col) == 1 && x.row == y.row)) {
    return false;
  }
  
  // Check out of bounds
  if (x.row < 0 || x.row >= maze.size() || x.col < 0 || x.col >= maze[0].size() || 
      y.row < 0 || y.row >= maze.size() || y.col < 0 || y.col >= maze[0].size()) 
  return false;

  // Check wall
  if (maze[x.row][x.col] == '#' || maze[y.row][y.col] == '#') {
    return false;
  }

  return true;
}