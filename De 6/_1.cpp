#include <string>
#include <cctype>
#include <iostream>

using namespace std;

int main() {
  string a, b;
  getline(cin, a);
  for (char aa : a) {
    if (!isalpha(aa) && aa != ' ') continue;
    b += tolower(aa);
  }
  cout << b;
}

