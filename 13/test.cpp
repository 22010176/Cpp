#include <iostream>

using namespace std;

class A {
public:
  void show() { cout << "A" << endl; }
};

class B : public A {
public:
  virtual void show() { cout << "B" << endl; }
};

class C : public B {
public:
  void show(int x) { cout << x << endl; }
};

int main() {
  B b;
  A& a = b;
  C c;

  a.show();
  b.show();
  c.show(10);
}