#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>

using namespace std;

// Hàm: 1000000 -> "1.000.000"
inline string formatMoney(long long money) {
  string s = to_string(money);
  int n = s.length() - 3;
  while (n > 0) {
    s.insert(n, ".");
    n -= 3;
  }
  return s;
}

#endif