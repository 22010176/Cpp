#include <iostream>

class Test {
public:
  int a, b;
  Test();
  Test(int i, int j);
  ~Test();
  void check();
};

Test::Test() { std::cout << "First\n"; }
Test::Test(int i, int j) {
  std::cout << "Second\n";
  a = i, b = j;
}

Test::~Test() { std::cout << "Out\n"; }
void Test::check() { Test t; }

int main() {
  Test t1, t2(5, 10);
  // First       (t1)
  // Second      (t2)

  std::cout << t1.a << ' ' << t1.b << '\n';
  // t1.a    t1.b

  std::cout << t2.a << ' ' << t2.b << '\n';
  // t2.a(5)    t2.b(10)

  t1.check();
  // First        (Create t inside Check function)
  // Out          (Destructor function run after finished Check function)

  // Out          (t1, t2 destructor run)
  // Out   


  // First
  // Second
  // 1 231
  // 5 10
  // First
  // Out
  // Out
  // Out
  return 0;
}