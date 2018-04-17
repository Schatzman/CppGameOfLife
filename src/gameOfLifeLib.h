#include <vector>

bool isAlive(char c);
int getLiveRowNeighbors(std::vector<char> row, int index);
int getAboveLiveRowNeighbors(std::vector<std::vector<char>> grid, int x, int y);
int getBelowLiveRowNeighbors(std::vector<std::vector<char>> grid, int x, int y);
int getLiveNeighbors(std::vector<std::vector<char>> grid, int x, int y);
std::vector<std::vector<char>> getNextIteration(std::vector<std::vector<char>> grid);
