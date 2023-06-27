#include <cctype>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
  auto input = std::fstream("../input/input3.txt");

  auto total = 0;
  for (std::string s; std::getline(input, s);) {
    auto unique_chars = std::set<char>();
    auto half_len = s.size() / 2;
    for (std::string::size_type i = 0; i < s.size(); i++) {
      if (i >= half_len) {
        if (unique_chars.contains(s[i])) {
          total += (isupper(s[i])) ? (s[i] - 'A' + 27) : (s[i] - 'a' + 1);
          break;
        }
      } else {
        unique_chars.insert(s[i]);
      }
    }
  }

  std::cout << total << std::endl;

  return 0;
}
