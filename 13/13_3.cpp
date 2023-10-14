#include <iostream>

using namespace std;

class A {
public:
  void show() const { cout << "A\n"; }
};

class B : public A {
public:
  using A::show;
  void show(int k) const { cout << k << '\n'; }
};

class C :public B {
public:
  using B::A::show;
  using B::show;
  void show(const char* c) const { cout << c << '\n'; }
};

int main() {
  B b;
  b.show(10);
  b.show();

  C c;
  c.show();
  c.show(30);
  c.show("ADSF");
}

