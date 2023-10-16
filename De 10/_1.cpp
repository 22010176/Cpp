#include <set>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> A = vector<int>{ 1, 2, 2, 3, 1, 4, 4, 5 };
  set<int> track;
  int c{};

  for (int i = 0; i < A.size();i++) {
    int x = A[i];
    c++;

    for (int j = i + 1; j < A.size();j++) if (A[j] == x) c++;

    int old = track.size();
    track.insert(x);
    if (old < track.size()) cout << x << "  " << c << endl;
    c = 0;
  }
}


