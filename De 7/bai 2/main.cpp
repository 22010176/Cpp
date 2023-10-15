#include "Score.cpp"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class A {
  int score;
public:
  A() : score(rand()) {}
  virtual void f() { cout << "A"; }
};

class B : public A {
public:
  B() : A() {}
  virtual void f() { cout << "B"; }
};
void a(A& a) {
  a.f();
}
int main() {
  B bb;
  A& b = bb;
  a(b);
}