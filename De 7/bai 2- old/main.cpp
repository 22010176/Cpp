#include "Score.cpp"

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void Solve() {
  vector<ScoreNatural> nature;
  vector<ScoreSocial> social;
  vector<Score*> sc;
  for (int i = 0; i < 3; i++) {
    ScoreNatural a;
    ScoreSocial b;
    nature.push_back(a);
    social.push_back(b);
    sc.push_back((Score*)&a);
    sc.push_back((Score*)&b);
  }
  for (Score* a : sc) cout << a->avgPoint() << endl;
}

int main() {
  srand(time(NULL));
  Solve();
  return 0;
}
