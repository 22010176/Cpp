#include "Score.cpp"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Solve() {
  vector<Score*> sc;
  vector<ScoreNatural> natural;
  vector<ScoreSocial> social;


  for (int i = 0; i < 10; i++) {
    ScoreNatural a;
    ScoreSocial b;

    natural.push_back(a);
    social.push_back(b);

    sc.push_back((Score*)&a);
    sc.push_back((Score*)&b);
  }


  for (Score* score : sc) cout << score->avgPoint() << endl;
  cout << "Highest avg: " << Score::getMaxAvg(sc) << endl;
  cout << "Lowest avg: " << Score::getMinAvg(sc) << endl;
  cout << "Highest pointA: " << Score::getMaxPointA(sc) << endl;
  cout << "Highest pointB: " << Score::getMaxPointB(sc) << endl;
  cout << "Highest pointC: " << Score::getMaxPointC(sc) << endl;
  cout << "Highest pointD: " << Score::getMaxPointD(sc) << endl;
}
int main() {
  srand(time(NULL));
  Solve();
  return 0;
}
