#include <string>
#include <iostream>

using namespace std;

int main() {
  string a = "255.111.111.111";
  string b = "";
  int j = 0;
  for (int i = 0; i < a.size();i++) {
    if (a[i] == '.') {
      int a = atoi(b.c_str());
      j++;
      if (a > 255 || a < 0 || j == 4 || b.size() == 0) {
        cout << 0;
        return 0;
      }
      b = "";
      continue;
    }
    b += a[i];
  }
  if (j == 3) cout << 1; else cout << 0;
}