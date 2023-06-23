#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  auto input = std::fstream("../input/input2.txt");

  int sum = 0;

  for (std::string line; std::getline(input, line);) {
    int left = line.substr(0, 1)[0] - 65;
    int right = line.substr(2, 3)[0] - 88;
    int winner = (3 + left - right) % 3;
    int score = right + 1;
    if (winner == 0) {
      score += 3;
    } else if (winner == 1) {
      score += 0;
    } else {
      score += 6;
    }
    sum += score;
  }

  std::cout << sum << std::endl;
  return 0;
}
