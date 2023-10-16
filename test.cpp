#include "Score.cpp"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class A {
public:
  virtual int score() {
    return 5;
  };
  virtual void f() { cout << "A"; }
};

class B : public A {
  int d = 90;
public:
  B() : A() {}

  int score() { return d; }
  virtual void f() { cout << "B"; }
};
class C : public A {
  int a = 34;
public:
  C() : A() {}
  // int score() { return a; }
  virtual void f() { cout << "B"; }
};

int main() {
  srand(time(NULL));

  vector<A*> vec;
  int len = rand() % 100;
  for (int i = 0; i < len;i++) {
    A* a;
    if (rand() % 2 == 0) {
      B b;
      a = &b;
    }
    else {
      C c;
      a = &c;
    }
    vec.push_back(a);
  }
  sort(vec.begin(), vec.end(), [](A*& a, A*& b) { return a->score() > b->score(); });
  for (int i = 0; i < vec.size();i++) cout << vec.at(i)->score() << " ";
}
