#include <iostream>

// g++ main.cpp -o main; ./main; del ./main.exe;

class T {
private:
  int a;
public:
  void show() { std::cout << a << '\n'; }
  friend void f(T& t);
};

void f(T& t) { t.a = 10; }

int main() {
  T t;

  f(t);
  t.show();

  return 0;
}