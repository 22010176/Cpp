#include <iostream>
#include "Rectangle.h"

using namespace std;

int main() {
  Rectangle r1(10.0, 10.0);
  Rectangle r2(15.0, 15.0);

  cout << r1.getWidth() << ' ' << r1.getLength() << endl;
  cout << r2.getWidth() << ' ' << r2.getLength() << endl;

  r2 = r1;
  cout << r1.getWidth() << ' ' << r1.getLength() << endl;
  cout << r2.getWidth() << ' ' << r2.getLength() << endl;

  return 0;
}