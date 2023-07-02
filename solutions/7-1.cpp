#include "../utils/util.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  auto input = fstream("../input/input7.txt");

  auto dirSizes = unordered_map<string, int>();
  auto currPath = vector<string>();

  for (string line; getline(input, line);) {
    auto parts = splitString(line, ' ');

    if (parts[0] == "$") {
      if (parts[1] == "cd") {
        if (parts[2] == "..") {
          currPath.pop_back();
        } else {
          currPath.push_back(parts[2]);
        }
      }
    } else if (parts[0] != "dir") {
      string pathStr;
      for (string folder : currPath) {
        pathStr += folder;
        dirSizes[pathStr] += stoi(parts[0]);
      }
    }
  }

  int total = 0;
  for (std::pair<const string, int> &n : dirSizes) {
    if (n.second <= 100000) {
      total += n.second;
    }
  }

  std::cout << total << std::endl;

  return 0;
}
