#include <iostream>
#include <thread>
#include <chrono>
#include "gameOfLifeLib.h"

void sleep(int ms) {
   std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void printGrid(std::vector<std::vector<char>> grid) {
   for (int i=0; i<(grid.size()-1); i++) {
      for (int j=0; j<(grid[i].size()-1); j++) {
         std::cout << grid[i][j] << "  ";
      }
      std::cout << std::endl;
   }
}

int main() {
   std::cout << "Welcome to Conway's Game of Life in C++!" << std::endl;
   sleep(3000);
   system("clear");
   std::vector<std::vector<char>> grid = {{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                          {'.', '.', '.', '.', '.', '.', '*', '.', '.'},
                                          {'.', '.', '*', '.', '.', '*', '*', '*', '.'},
                                          {'.', '*', '*', '*', '.', '.', '*', '.', '.'},
                                          {'.', '.', '*', '.', '.', '.', '.', '.', '.'}};
   std::vector<std::vector<char>> nextG(grid.size(), std::vector<char>(grid[0].size(), '.'));
   printGrid(grid);
   sleep(300);
   system("clear");
   for (int i=0; i<1000; i++) {
      nextG = getNextIteration(grid);
      grid = nextG;
      printGrid(grid);
      sleep(300);
      system("clear");
   }
}
