#include "../utils/util.h"
#include <algorithm>
#include <array>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printSol(vector<vector<char>> v) {
  for (auto &c : v) {
    if (!c.empty()) {
      std::cout << c.front();
    }
  }
  std::cout << std::endl;
}

void reorderMulti(int from, int to, int n, vector<vector<char>> &v, bool rev) {
  auto tmp = vector<char>(v[from].begin(), v[from].begin() + n);
  v[from].erase(v[from].begin(), v[from].begin() + n);
  if (rev) {
    v[to].insert(v[to].begin(), tmp.rbegin(), tmp.rend());
  } else {
    v[to].insert(v[to].begin(), tmp.begin(), tmp.end());
  }
}

int main() {
  auto input = fstream("../input/input5.txt");
  auto first = vector<vector<char>>(10, vector<char>());

  for (string line; getline(input, line);) {
    if (line[1] == '1') {
      break;
    }
    for (size_t i = 1, j = 1; i < line.size(); i += 4, j++) {
      char c = line[i];
      if (c != ' ') {
        first[j].push_back(c);
      }
    }
  }

  auto second = vector<vector<char>>(first.begin(), first.end());

  string s;
  getline(input, s);

  for (string line; getline(input, line);) {
    auto str = splitString(line, ' ');
    int amount = stoi(str[1]);
    int from = stoi(str[3]);
    int to = stoi(str[5]);
    reorderMulti(from, to, amount, first, true);
    reorderMulti(from, to, amount, second, false);
  }

  printSol(first);
  printSol(second);

  return 0;
}
