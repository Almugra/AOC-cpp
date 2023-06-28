#include "../utils/util.h"
#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  auto input = fstream("../input/input5.txt");
  auto stacks = vector<deque<char>>(10, deque<char>());

  for (string line; getline(input, line);) {
    if (line[1] == '1') {
      break;
    }
    for (size_t i = 1, j = 1; i < line.size(); i += 4, j++) {
      char c = line[i];
      if (c != ' ') {
        stacks[j].push_back(c);
      }
    }
  }

  string s;
  getline(input, s);

  for (string line; getline(input, line);) {
    auto str = splitString(line, ' ');
    for (int i = 1; i <= stoi(str[1]); i++) {
      int from = stoi(str[3]);
      int to = stoi(str[5]);
      char tmp = stacks[from].front();
      stacks[from].pop_front();
      stacks[to].push_front(tmp);
    }
  }

  for (auto &c : stacks) {
    if (!c.empty()) {
      std::cout << c.front();
    }
  }
  std::cout << std::endl;

  return 0;
}
