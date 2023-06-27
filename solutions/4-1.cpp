#include "../utils/util.h"
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool contains(vector<int> &r1, vector<int> &r2) {
  return r1[0] <= r2[0] && r1[1] >= r2[1];
}

int main() {
  auto input = fstream("../input/input4.txt");

  int count = 0;

  for (string s; getline(input, s);) {
    auto pairs = splitByDelimString(s, ',');
    auto r1 = splitByDelimInt(pairs[0], '-');
    auto r2 = splitByDelimInt(pairs[1], '-');

    if (contains(r1, r2) || contains(r2, r1)) {
      count++;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
