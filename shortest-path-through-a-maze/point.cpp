#include <iostream>
#include "point.hpp"

bool operator==(const Point& x, const Point& y) {
  return (x.row == y.row) and (x.col == y.col);
}

bool operator!=(const Point& x, const Point& y) {
  return not (x == y);
}

bool operator<(const Point& x, const Point& y) {
  return (x.row < y.row) or (x.row == y.row and x.col < y.col);
}

Point operator+(const Point& x, const Point& y) {
  return {x.row + y.row, x.col + y.col};
}

std::ostream& operator<<(std::ostream& out, const Point& x) {
  out << '{' << x.row << ", " << x.col << '}';
  return out;
}
