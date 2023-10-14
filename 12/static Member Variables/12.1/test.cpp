#include <iostream>
#include "test.h"

int T::num = 5;

int main() {
  T t[10];

  t[2].num = 20;
  std::cout << t[5].num << '\n';

  return 0;
}