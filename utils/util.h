#ifndef UTIL
#define UTIL

#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> splitByDelimString(string s, char d) {
  auto ss = stringstream(s);
  auto v = vector<string>();
  for (string tmp; getline(ss, tmp, d);) {
    v.push_back(tmp);
  }
  return v;
}

vector<int> splitByDelimInt(string s, char d) {
  auto ss = stringstream(s);
  auto v = vector<int>();
  for (string tmp; getline(ss, tmp, d);) {
    v.push_back(stoi(tmp));
  }
  return v;
}

#endif // !UTIL
