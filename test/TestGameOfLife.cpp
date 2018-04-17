#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "gameOfLifeLib.h"

TEST(TestGameOfLife, isAliveExpectTrue) {
   EXPECT_TRUE(isAlive('*'));
}

TEST(TestGameOfLife, isAliveExpectFalse) {
   EXPECT_FALSE(isAlive('.'));
}

TEST(TestGameOfLife, getLiveRowNeighborsExpectTwo) {
   std::vector<char> row = {'*', '*', '*'};
   EXPECT_EQ(2, getLiveRowNeighbors(row, 1));
}

TEST(TestGameOfLife, getLiveRowNeighborsExpectZero) {
   std::vector<char> row = {'.', '*', '.'};
   EXPECT_EQ(0, getLiveRowNeighbors(row, 1));
}

TEST(TestGameOfLife, getAboveLiveRowNeighborsExpectThree) {
   std::vector<std::vector<char>> grid = {{'.', '*', '*', '*'},
                                          {'.', '.', '*', '.'},
                                          {'*', '*', '.', '.'}};
   EXPECT_EQ(3, getAboveLiveRowNeighbors(grid, 2, 1));
}

TEST(TestGameOfLife, getAboveLiveRowNeighborsExpectZero) {
   std::vector<std::vector<char>> grid = {{'.', '.', '.', '.'},
                                          {'.', '.', '*', '.'},
                                          {'*', '*', '.', '.'}};
   EXPECT_EQ(0, getAboveLiveRowNeighbors(grid, 2, 1));
}

TEST(TestGameOfLife, getBelowLiveRowNeighborsExpectThree) {
   std::vector<std::vector<char>> grid = {{'.', '.', '.', '.'},
                                          {'.', '.', '*', '.'},
                                          {'*', '*', '*', '*'}};
   EXPECT_EQ(3, getBelowLiveRowNeighbors(grid, 2, 1));
}

TEST(TestGameOfLife, getBelowLiveRowNeighborsExpectZero) {
   std::vector<std::vector<char>> grid = {{'.', '.', '.', '.'},
                                          {'.', '.', '*', '.'},
                                          {'*', '.', '.', '.'}};
   EXPECT_EQ(0, getBelowLiveRowNeighbors(grid, 2, 1));
}

TEST(TestGameOfLife, getLiveNeighborsExpectEight) {
   std::vector<std::vector<char>> grid = {{'.', '*', '*', '*'},
                                          {'.', '*', '*', '*'},
                                          {'*', '*', '*', '*'}};
   EXPECT_EQ(8, getLiveNeighbors(grid, 2, 1));
}

TEST(TestGameOfLife, getLiveNeighborsExpectZero) {
   std::vector<std::vector<char>> grid = {{'.', '.', '.', '.'},
                                          {'.', '.', '*', '.'},
                                          {'*', '.', '.', '.'}};
   EXPECT_EQ(0, getLiveNeighbors(grid, 2, 1));
}

TEST(TestGameOfLife, getNextIterationExpectOneNewLivingCell) {
   std::vector<std::vector<char>> grid0 = {{'.', '.', '.', '.'},
                                           {'.', '*', '*', '.'},
                                           {'.', '*', '.', '.'}};
   std::vector<std::vector<char>> grid1 = getNextIteration(grid0);
   std::vector<std::vector<char>> expectedGrid1 = {{'.', '.', '.', '.'},
                                                   {'.', '*', '*', '.'},
                                                   {'.', '*', '*', '.'}};
   for (int i=0; i < (expectedGrid1.size()-1); i++) {
      for (int j=0; j < (expectedGrid1[i].size()-1); j++) {
         EXPECT_EQ(expectedGrid1[i][j], grid1[i][j]);
      }
   }
}

