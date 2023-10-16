#ifndef _SCORE_H_
#define _SCORE_H_

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Score {
private:
  double math, literature, english;
public:
  Score() : math{ double(rand() % 10) }, literature{ double(rand() % 10) }, english{ double(rand() % 10) } {}
  Score(double math, double literature, double english) : math(math), literature(literature), english(english) {}

  double getMath() const { return math; }
  double getEnglish() const { return english; }
  double getLiterature() const { return literature; }

  virtual double pointA() const { return 0; };
  virtual double pointB() const { return 0; };
  virtual double pointC() const { return 0; };
  virtual double pointD() const { return math + literature + english; };
  virtual bool isPass() const = 0;
  virtual double avgPoint() const = 0;

  static double getMaxAvg(vector<Score*>& vt) { return max_element(vt.begin(), vt.end(), [](Score*& a, Score*& b) {return a->avgPoint() < b->avgPoint();})[0]->avgPoint(); }
  static double getMinAvg(vector<Score*>& vt) { return min_element(vt.begin(), vt.end(), [](Score*& a, Score*& b) {return a->avgPoint() < b->avgPoint();})[0]->avgPoint(); }
  static double getMaxPointA(vector<Score*>& vt) { return max_element(vt.begin(), vt.end(), [](Score*& a, Score*& b) {return a->pointA() < b->pointA();})[0]->pointA(); }
  static double getMaxPointB(vector<Score*>& vt) { return max_element(vt.begin(), vt.end(), [](Score*& a, Score*& b) {return a->pointB() < b->pointB();})[0]->pointB(); }
  static double getMaxPointC(vector<Score*>& vt) { return max_element(vt.begin(), vt.end(), [](Score*& a, Score*& b) {return a->pointC() < b->pointC();})[0]->pointC(); }
  static double getMaxPointD(vector<Score*>& vt) { return max_element(vt.begin(), vt.end(), [](Score*& a, Score*& b) {return a->pointD() < b->pointD();})[0]->pointD(); }

  friend ostream& operator<<(ostream& out, Score& sc) {
    out << sc.getMath() << " " << sc.getLiterature() << " " << sc.getEnglish();
    return out;
  }
};

class ScoreNatural : public Score {
private:
  double physic, chemistry, biology;
public:
  ScoreNatural() : Score(), physic{ double(rand() % 10) }, chemistry{ double(rand() % 10) }, biology{ double(rand() % 10) } {}
  ScoreNatural(double math, double literature, double english, double physic, double chemistry, double biology) : Score(math, literature, english), physic{ physic }, chemistry{ chemistry }, biology{ biology } {}

  double getPhysic() const { return physic; }
  double getBiology() const { return biology; }
  double getChemistry() const { return chemistry; }

  double pointA() const { return getMath() + physic + chemistry; }
  double pointB() const { return getMath() + chemistry + biology; }
  double pointNatural() const { return physic + chemistry + biology; }

  bool isPass() const { return avgPoint() > 5; }
  double avgPoint() const { return(getMath() + getLiterature() + getEnglish() + physic + biology + chemistry) / 6; }
  friend ostream& operator<<(ostream& out, ScoreNatural& sc) {
    cout << "good" << endl;
    out << (Score&)sc << " " << sc.getPhysic() << " " << sc.getChemistry() << " " << sc.getBiology();
    return out;
  }
};

class ScoreSocial : public Score {
private:
  double ce, geography, history;
public:
  ScoreSocial() : Score(), ce{ double(rand() % 10) }, geography{ double(rand() % 10) }, history{ double(rand() % 10) } {}
  ScoreSocial(double math, double literature, double english, double ce, double geography, double history) : Score(math, literature, english), ce(ce), geography(geography), history(history) {}

  double getCe() const { return ce; }
  double getHistory() const { return history; }
  double getGeography() const { return geography; }

  double pointC() const { return getLiterature() + history + geography; }
  double pointSocial() const { return ce + geography + history; }

  bool isPass() const { return avgPoint() > 5; }
  double avgPoint() const { return (getMath() + getLiterature() + getEnglish() + geography + ce + history) / 6; }
  friend ostream& operator<<(ostream& out, ScoreSocial& sc) {
    out << (Score&)sc << " " << sc.getCe() << " " << sc.getGeography() << " " << sc.getHistory();
    return out;
  }
};
#endif
