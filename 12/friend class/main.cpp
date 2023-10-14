#include <iostream>
#include <string>

using namespace std;

class System {
private:
  int type;
  string IP_addr;
public:
  friend class Net_Mgt;
  enum { PC, Switch, Router };
  void show() const { cout << "Type: " << type << " IP: " << IP_addr << endl; }
};

class Net_Mgt {
public:
  void set_type(System& s, int type) { s.type = type; }
  void set_IP(System& s, const string addr) const { s.IP_addr = addr; }
  void show(System& s) const { s.show(); }
};

int main() {
  System s;

  Net_Mgt mgt;
  mgt.set_type(s, System::PC);
  mgt.set_IP(s, "192.168.1.2");
  mgt.show(s);
  return 0;
}