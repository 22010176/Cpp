#include <iostream>

class A {
private:
  int x, v;
public:
  A(int i, int j = 0) { x = i;v = j; } // no defautl constructor
};

class A_ {
private:
  int x = 19, v = 20;
public:
  A_() {}
  A_(int i) { x = i; }
  A_(int i, int j) { x = i, v = j; }
};

int main() {
}