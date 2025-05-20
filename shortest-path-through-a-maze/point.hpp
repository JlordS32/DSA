#ifndef POINT_HPP_
#define POINT_HPP_

#include <iostream>

struct Point {
  int row {};
  int col {};
};

bool operator==(const Point& x, const Point& y);

bool operator!=(const Point& x, const Point& y);

bool operator<(const Point& x, const Point& y);

Point operator+(const Point& x, const Point& y);

std::ostream& operator<<(std::ostream& out, const Point& x);

#endif    // POINT_HPP_
