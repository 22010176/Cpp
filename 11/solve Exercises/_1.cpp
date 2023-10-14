class T {
private:
  int a;
public:
  friend int f();
  // void r(const T& t) { t.a = a; }
  // void g(int b) const { a = b; }
};
int f() {
  // return a;
}