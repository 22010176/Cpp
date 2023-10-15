#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const string a = "BGK";

bool Check(char a, char b) { return (a == 'b' && b == 'g') || (a == 'g' && b == 'k') || (a == 'k' && b == 'b'); }
bool Check1(char a) { return a == 'b' || a == 'g' || a == 'k'; }

int main() {
  string a, b;
  cin >> a >> b;

  if (a.size() != b.size()) {
    cout << "Error" << endl;
    return 0;
  }

  int _A{}, _B{};
  for (int i = 0; i < a.size();i++) {
    char aa = tolower(a[i]), bb = tolower(b[i]);
    if (!Check1(aa) || !Check1(bb)) {
      cout << "Error" << endl;
      return 0;
    }

    if (aa == bb) continue;
    else if (Check(aa, bb)) _A++;
    else if (!Check(aa, bb)) _B++;
  }

  if (_A == _B) cout << "Hoa" << endl;
  else if (_A > _B) cout << 'B' << endl;
  else cout << 'A' << endl;
}