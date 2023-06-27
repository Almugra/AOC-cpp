#ifndef UTIL_H
#define UTIL_H

#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> splitByDelimString(const string &s, char d) {
  auto ss = stringstream(s);
  auto v = vector<string>();
  for (string tmp; getline(ss, tmp, d);) {
    v.emplace_back(tmp);
  }
  return v;
}

vector<int> splitByDelimInt(const string &s, char d) {
  auto ss = stringstream(s);
  auto v = vector<int>();
  for (string tmp; getline(ss, tmp, d);) {
    v.emplace_back(stoi(tmp));
  }
  return v;
}

#endif // !UTIL_H
