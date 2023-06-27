#ifndef UTIL_H
#define UTIL_H

#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> splitString(const string &src, const char &splitter) {
  vector<string> vec;
  string c;
  for (const char &t : src) {
    if (t == splitter) {
      vec.push_back(c);
      c.clear();
    } else {
      c.push_back(t);
    }
  }
  vec.push_back(c);
  return vec;
}

vector<int> splitInt(const string &src, const char &splitter) {
  vector<int> vec;
  string c;
  for (const char &t : src) {
    if (t == splitter) {
      vec.push_back(stoi(c));
      c.clear();
    } else {
      c.push_back(t);
    }
  }
  vec.push_back(stoi(c));
  return vec;
}

#endif // !UTIL_H
