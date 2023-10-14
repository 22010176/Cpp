#include <iostream>
#include "Tree.h"

int main() {
  Tree oak;
  Tree elm;
  Tree pine;

  std::cout << " The number of trees: " << elm.getObjectCount() << ' ' << Tree::getObjectCount() << std::endl;

  return 0;
}