#include <iostream>

// g++ main2.cpp -o main2; ./main2; del ./main2.exe;

class T;

class anotherClassT {
public:
  void another_f(T& t);
};

class T {
private: int a;
public:
  void show() { std::cout << a << "\n"; }
  friend void anotherClassT::another_f(T& t);
};

void anotherClassT::another_f(T& t) {
  t.a = 10;
  std::cout << t.a << std::endl;
}

int main() {
  T t1;
  anotherClassT t2;
  t2.another_f(t1);
  return 0;
}