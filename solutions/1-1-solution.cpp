#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  auto input = std::fstream("../input/input1.txt");
  auto max_cals = 0;

  auto current_cals = 0;
  for (std::string line; std::getline(input, line);) {
    if (line.empty()) {
      max_cals = std::max(max_cals, current_cals);
      current_cals = 0;
    } else {
      current_cals += std::stoi(line);
    }
  }

  std::cout << max_cals << std::endl;

  return 0;
}

