#include <set>
#include <iostream>
#include <vector>

using namespace std;

struct _1 {
  int val, times;
  _1(int val) : val{ val }, times{ 0 } {}
  // _1(_1& a) { times++; }
  _1& operator++() {
    times++;
    return *this;
  }
  _1 operator++(int) {
    _1 a = *this; ++*this;
    return a;
  }
  bool operator<(_1& other) { return val < other.val; }
  bool operator>(_1& other) { return val > other.val; }
  ostream& operator<<(ostream& out) {
    out << val << " " << times;
    return out;
  }
};

int main() {
  vector<int> A{ 1, 2, 2, 3, 1, 4, 4, 5 };
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


