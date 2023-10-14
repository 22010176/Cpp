#include <iostream>

using namespace std;

class A {
public:
  A(int k) { cout << "A: " << k << endl; }
  ~A() { cout << " ~A\n"; }
};

class B : public A {
public:
  B(int k) : A(k + 1) { cout << "B: " << k << endl; }
  ~B() { cout << " ~B\n"; }
};

class C : public B {
public:
  C(int k) : B(k * 2) { cout << "C: " << k << endl; }
  ~C() { cout << " ~C\n"; }
};

int main() {
  C c(10);
  return 0;
}