#include <string>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void findAndPrintUncommonChars(const string& str1, const string& str2) {
  set<char> a;
  string t = str1 + str2;
  for (int i = 0; i < t.size();i++) a.insert(t.at(i));

  vector<char> b(a.begin(), a.end());
  for (int i = 0; i < b.size();i++) {
    if (str1.find(b.at(i)) < str1.size() - 1 && str2.find(b.at(i)) < str2.size() - 1) continue;
    cout << b.at(i);
  }
}

int main() {
  string a = "egeksfroeegks", b = "eegksquiz";
  findAndPrintUncommonChars(a, b);
}