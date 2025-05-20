#include <vector>
#include <string>
#include <queue>
#include <map>
#include "maze_solver.hpp"
#include "point.hpp"

std::vector<std::string> solveMaze(const std::vector<std::string> &maze,
                                   const Point &start, const Point &finish)
{
   // Initial setup
   int rows = maze.size();
   int cols = maze[0].size();
   std::vector<std::string> result = maze;
   std::map<Point, Point> prev;
   std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
   std::queue<Point> q;
   std::vector<Point> directions {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

   // Start 
   q.push(start);
   visited[start.row][start.col] = true;

   // BFS Implementation
   while (!q.empty()) {
      Point current = q.front();
      q.pop();

      // Get all possible direction from current point
      for (const auto direction : directions) {
         Point next = current + direction;
         bool isOutOfBounds = next.row < 0 || next.row >= rows || next.col < 0 || next.col >= cols;

         // If not out of bounds and is not visited.
         if (!isOutOfBounds && maze[next.row][next.col] == ' ' && !visited[next.row][next.col]) {
            visited[next.row][next.col] = true;
            q.push(next);
            prev[next] = current;
         }
      }
   }

   // Reconstruct path
   Point current = finish;
   while (current != start) {
      result[current.row][current.col] = '.';
      current = prev[current];
   }
   result[current.row][current.col] = '.';

   return result;
}

