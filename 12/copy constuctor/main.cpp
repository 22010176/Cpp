#include <iostream>

class T {
private:
  int a, b;
public:
  T(int i, int j) { a = i, b = j; }
  void show() const { std::cout << a << ' ' << b << '\n'; }
};

int main() {
  T t1(1, 2);
  T t2(t1);  // default copy constructor is called
  T t3 = t1;
  std::cout << &t2 << ' ' << &t1 << std::endl;
  // t2.show();
  // t3.show();

  return 0;
}