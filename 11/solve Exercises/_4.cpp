# include <iostream>
# include <string>
# include <vector>
using namespace std;

class Employee {
private:
  string name;
  float sal;

public:
  void set(const string& n, float s);
  float get() const;
  void show() const;
};

void Employee::set(const string& n, float s) { name = n, sal = s; }
float Employee::get() const { return sal; }
void Employee::show() const { cout << "N:" << name << " S:" << sal << '\n'; }

int main() {
  int i, pos;
  float base, sal, max_sal;

  string name;
  Employee tmp;
  vector < Employee > empl;

  while (1) {
    cout << "\nName : ";
    getline(cin, name);
    cout << " Salary : ";
    cin >> sal;
    if (sal == -1)
      break;
    tmp.set(name, sal);
    empl.push_back(tmp);
    cin.get(); // Extract the new line character .
  }

  cout << "\nEnter base : ";
  cin >> base;
  max_sal = -1;

  for (i = 0; i < empl.size(); i++) {
    sal = empl[i].get();

    if (sal > base) empl[i].show();
    if (sal > max_sal) {
      pos = i;
      max_sal = sal;
    }
  }
  if (max_sal != -1) empl[pos].show();
  return 0;
}