#include "gameOfLifeLib.h"

bool isAlive(char c) {
   if (c == '*') {
      return true;
   }
   return false;
}

int getLiveRowNeighbors(std::vector<char> row, int index) {
   int count = 0;
   if (index > 0) {
      if (isAlive(row[index-1])) {
         count++;
      }
   }
   if ((index + 1) < row.size()) {
      if (isAlive(row[index+1])) {
         count++;
      }
   }
   return count;
}

int getAboveLiveRowNeighbors(std::vector<std::vector<char>> grid, int x, int y) {
   int count = 0;
   if (y > 0) {
      count += getLiveRowNeighbors(grid[y-1], x);
      if (isAlive(grid[y-1][x])) {
         count++;
      }
   }
   return count;
}

int getBelowLiveRowNeighbors(std::vector<std::vector<char>> grid, int x, int y) {
   int count = 0;
   if ((y+1) < grid.size()) {
      count += getLiveRowNeighbors(grid[y+1], x);
      if (isAlive(grid[y+1][x])) {
         count++;
      }
   }
   return count;
}

int getLiveNeighbors(std::vector<std::vector<char>> grid, int x, int y) {
   int count = 0;
   count += getLiveRowNeighbors(grid[y], x);
   count += getAboveLiveRowNeighbors(grid, x, y);
   count += getBelowLiveRowNeighbors(grid, x, y);
   return count;
}

std::vector<std::vector<char>> getNextIteration(std::vector<std::vector<char>> grid) {
   std::vector<std::vector<char>> newGrid(grid.size(), std::vector<char>(grid[0].size(), '.'));
   for (int i=0; i < (grid.size()-1); i++) {
      for (int j=0; j < (grid[i].size()-1); j++) {
         int neighborCount = getLiveNeighbors(grid, j, i);
         bool cellAlive = isAlive(grid[i][j]);
         char nextCell;
         if (cellAlive) {
            if (neighborCount > 3 || neighborCount < 2) {
               nextCell = '.';
            } else {
               nextCell = '*';
            }
         } else {
            if (neighborCount == 3) {
               nextCell = '*';
            } else {
               nextCell = '.';
            }
         }
         newGrid[i][j] = nextCell;
      }
   }
   return newGrid;
}

// Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
// Any live cell with two or three live neighbours lives on to the next generation.
// Any live cell with more than three live neighbours dies, as if by overpopulation.
// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
