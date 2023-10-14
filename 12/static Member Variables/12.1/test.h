#ifndef _TEST_H_
#define _TEST_H_

class T {
private:
  int v;
  double d;
public:
  static inline int num = 4; // since C++17
  void set() { v = num; }
};
#endif