#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main() {
  auto input = fstream("../input/input8.txt");
  auto grid = vector<vector<int>>();

  for (string line; getline(input, line);) {
    auto v = vector<int>();
    for (char &c : line) {
      v.push_back(c - 48);
    }
    grid.push_back(v);
  }

  int border_trees = static_cast<int>(grid.size()) * 2 +
                     (static_cast<int>(grid[0].size()) - 2) * 2;
  int visible_trees = border_trees;
  for (int y = 1; y < static_cast<int>(grid.size()) - 1; y++) {
    for (int x = 1; x < static_cast<int>(grid[0].size()) - 1; x++) {
      auto curr = grid[y][x];

      int left_max = 0;
      for (int i = 0; i < x; i++) {
        left_max = max(left_max, grid[y][i]);
      }

      int right_max = 0;
      for (int i = x + 1; i < static_cast<int>(grid[y].size()); i++) {
        right_max = max(right_max, grid[y][i]);
      }

      int top_max = 0;
      for (int i = 0; i < y; i++) {
        top_max = max(top_max, grid[i][x]);
      }

      int bot_max = 0;
      for (int i = y + 1; i < static_cast<int>(grid.size()); i++) {
        bot_max = max(bot_max, grid[i][x]);
      }

      if (left_max < curr || right_max < curr || top_max < curr ||
          bot_max < curr) {
        visible_trees++;
      }
    }
  }

  std::cout << visible_trees << std::endl;

  return 0;
}
