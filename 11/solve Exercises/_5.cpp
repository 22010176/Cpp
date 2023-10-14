#include <iostream>

class Rect {
private:
  float l, h;
public:
  Rect(float a, float b) { l = a; h = b; }
  float area() const { return l * h; }
};
class Circle {
private:
  float r;
public:
  Circle(float a) { r = a; }
  float area() const { return r * r * 3.14; }
};
template <typename T> float f(T t) { return t->area(); }

int main() {
  Rect r(1, 2);
  Circle c(3);
  std::cout << f(&r) << ' ' << f(&c) << '\n';
  return 0;
}
