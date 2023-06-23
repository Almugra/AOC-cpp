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
    int outcome = line.substr(2, 3)[0];
    int score = 0;
    if (outcome == 'X') {
      score += ((3 + left - 1) % 3) + 1;
    } else if (outcome == 'Y') {
      score += 3 + left + 1;
    } else {
      score += 6 + ((left + 1) % 3) + 1;
    }
    sum += score;
  }

  std::cout << sum << std::endl;
  return 0;
}
