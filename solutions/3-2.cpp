#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
  auto input = std::fstream("../input/input3.txt");

  int total = 0;

  std::unordered_map<char, int> unique_chars_map;

  for (std::string s; std::getline(input, s);) {

    std::set<char> unique_chars(s.begin(), s.end());

    for (char c : unique_chars) {
      unique_chars_map[c]++;

      if (unique_chars_map[c] == 3) {
        total += isupper(c) ? (c - 'A' + 27) : (c - 'a' + 1);
        unique_chars_map.clear();
        break;
      }
    }
  }

  std::cout << total << std::endl;

  return 0;
}
