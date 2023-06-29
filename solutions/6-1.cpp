#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int main() {
  auto input = fstream("../input/input6.txt");
  string line;
  getline(input, line);

  size_t partOne = 0;
  size_t partTwo = 0;

  auto map = unordered_map<char, size_t>();
  size_t left = 0;
  size_t right = 0;
  while (right < line.size()) {
    if (map[line[right]] >= left) {
      left = map[line[right]] + 1;
    }
    if (right - left == 3 && partOne == 0) {
      partOne = right + 1;
    }
    if (right - left == 13 && partTwo == 0) {
      partTwo = right + 1;
    }
    map[line[right]] = right;
    right++;
  }

  std::cout << partOne << std::endl;
  std::cout << partTwo << std::endl;
  return 0;
}
