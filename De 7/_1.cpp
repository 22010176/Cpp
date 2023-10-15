#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {

  string a = "abcef14&f", b = "b1&";
  if (b.size() > a.size()) {
    cout << 0;
    return 0;
  }

  int las = 0;
  for (char bb : b) {
    int i = a.find(bb);
    if (i > a.size() || i < las) {
      cout << 0;
      return 0;
    }
    las = i;
  }

  int i = 0;
  for (int j = 0; j < a.size();j++) {
    if (a[j] == b[i]) {
      i++;
      continue;
    }
    cout << j << " ";
  }

  return 0;
}
