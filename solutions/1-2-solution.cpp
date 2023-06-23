#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  auto input = std::fstream("../input/input1.txt");
  auto vec = std::vector<int>();

  auto current_cals = 0;
  for (std::string line; std::getline(input, line);) {
    if (line.empty()) {
      vec.push_back(std::max(current_cals, current_cals));
      current_cals = 0;
    } else {
      current_cals += std::stoi(line);
    }
  }

  std::sort(vec.begin(), vec.end());

  auto SumOfTopThree =
      vec[vec.size() - 1] + vec[vec.size() - 2] + vec[vec.size() - 3];

  std::cout << SumOfTopThree << std::endl;

  return 0;
}
