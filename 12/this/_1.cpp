#include <iostream>

class T {
private:
  int a;
public:
  void set(int i) { this->a = i; }
  int get() { return this->a; }
};


int main() {
  T t;

  t.set(2);
  std::cout << "a: " << t.get() << '\n';

  return 0;
}