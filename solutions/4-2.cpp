#include "../utils/util.h"
#include <fstream>
#include <iostream>
using namespace std;

bool overlap(vector<int> &r1, vector<int> &r2) {
  return r1[1] <= r2[1] && r1[1] >= r2[0];
}

int main() {

  auto input = fstream("../input/input4.txt");

  int count = 0;

  for (string s; getline(input, s);) {
    auto pairs = splitString(s, ',');
    auto r1 = splitInt(pairs[0], '-');
    auto r2 = splitInt(pairs[1], '-');

    if (overlap(r1, r2) || overlap(r2, r1)) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
