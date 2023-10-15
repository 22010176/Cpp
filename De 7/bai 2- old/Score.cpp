#ifndef _SCORE_H_
#define _SCORE_H_

#include <vector>
#include  <algorithm>
#include <iostream>

using namespace std;

class Score {
private:
  double math, literature, english;
public:
  Score() : math{ rand() % 10 }, literature{ rand() % 10 }, english{ rand() % 10 } {}
  Score(double math, double literature, double english) : math(math), literature(literature), english(english) {}

  double getMath() { return math; }
  double getLiterature() { return literature; }
  double getEnglish() { return english; }

  virtual double pointA() { return 0; };
  virtual double pointB() { return 0; };
  virtual double pointC() { return 0; };
  virtual double pointD() { return 0; };
  virtual bool isPass() { return false; };
  virtual double avgPoint() = 0;

  static double getMaxAvg(vector<Score*> vt) {
    vector<Score*> a = vt;
    max(a.begin(), a.end(), [](Score*& a, Score*& b) {return a->avgPoint() > b->avgPoint();});
    return a[0]->avgPoint();
  }
  static double getMinAvg(vector<Score*> vt) {
    vector<Score*> a = vt;
    max(a.begin(), a.end(), [](Score*& a, Score*& b) {return a->avgPoint() < b->avgPoint();});
    return a[0]->avgPoint();
  }
  static double getMaxPointA(vector<Score*> vt) {
    vector<Score*> a = vt;
    max(a.begin(), a.end(), [](Score*& a, Score*& b) {return a->pointA() > b->pointA();});
    return a[0]->pointA();
  }
  static double getMaxPointB(vector<Score*> vt) {
    vector<Score*> a = vt;
    max(a.begin(), a.end(), [](Score*& a, Score*& b) {return a->pointB() > b->pointB();});
    return a[0]->pointB();
  }
  static double getMaxPointC(vector<Score*> vt) {
    vector<Score*> a = vt;
    max(a.begin(), a.end(), [](Score*& a, Score*& b) {return a->pointC() > b->pointC();});
    return a[0]->pointC();
  }
  static double getMaxPointD(vector<Score*> vt) {
    vector<Score*> a = vt;
    max(a.begin(), a.end(), [](Score*& a, Score*& b) {return a->pointD() > b->pointD();});
    return a[0]->pointD();
  }
};

class ScoreNatural : public Score {
private:
  double physic, chemistry, biology;
public:
  ScoreNatural() : Score(), physic{ rand() % 10 }, chemistry{ rand() % 10 }, biology{ rand() % 10 } {}
  ScoreNatural(double math, double literature, double english, double physic, double chemistry, double biology) : Score(math, literature, english), physic{ physic }, chemistry{ chemistry }, biology{ biology } {}

  double getPhysic() { return physic; }
  double Chemistry() { return chemistry; }
  double Biology() { return biology; }

  double pointA() { return getMath() + physic + chemistry; }
  double pointB() { return getMath() + chemistry + biology; }
  double pointNatural() { return physic + chemistry + biology; }

  bool isPass() { return avgPoint() > 5; }
  double avgPoint() { return(getMath() + getLiterature() + getEnglish() + physic + biology + chemistry) / 6; }
};

class ScoreSocial : public Score {
private:
  double ce, geography, history;
public:
  ScoreSocial() : Score(), ce{ rand() % 10 }, geography{ rand() % 10 }, history{ rand() % 10 } {}
  ScoreSocial(double math, double literature, double english, double ce, double geography, double history) : Score(math, literature, english), ce(ce), geography(geography), history(history) {}

  double getCe() { return ce; }
  double getGeography() { return geography; }
  double getHistory() { return history; }

  double pointC() { return getLiterature() + history + geography; }
  double pointD() { return getMath() + getLiterature() + getEnglish(); }
  double pointSocial() { return ce + geography + history; }

  bool isPass() { return avgPoint() > 5; }
  double avgPoint() { return (getMath() + getLiterature() + getEnglish() + geography + ce + history) / 6; }
};
#endif
