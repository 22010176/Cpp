#include <iostream>

using namespace std;

class T {
private:
  int* value;
public:
  T(int val = 0) { value = new int{ val }; }
  T(const T& t);
  int getVal() { return *value; }
  void setVal(int v) { *value = v; }
};

T::T(const T& t) { value = new int;  *value = *(t.value); }
int main() {
  T ob1(5);
  T ob2 = ob1;

  ob2.setVal(20);
  cout << ob2.getVal() << ' ' << ob1.getVal() << std::endl;
}