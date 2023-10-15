#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

#include "Person.cpp"

using namespace std;

void Solve() {
  vector<Person*> person;
  vector <EmployeeFT> ft;
  for (int i = 0; i < 10; i++) {
    EmployeeFT _p;
    ft.push_back(_p);
    person.push_back(static_cast<Person*>(&_p));
  }
  cout << "Full-time: " << endl;
  for (EmployeeFT& a : ft) a.display();

  cout << "Max salary full time: \n" << EmployeeFT::getMaxSalary(ft)[0] << endl;

  vector <EmployeePT> pt;
  for (int i = 0; i < 4; i++) {
    EmployeePT _p;
    pt.push_back(_p);
    person.push_back(static_cast<Person*>(&_p));
  }
  cout << "part-time: " << endl;
  for (EmployeePT& a : pt) a.display();
  cout << "Max salary part time: \n" << EmployeePT::getMaxSalary(pt)[0] << endl;

  vector<Person*> a = Person::findPerson(person);
  cout << "HN: " << endl;
  for (Person* p : a) p->display();
}

int main() {
  srand(time(NULL));
  Solve();
  return 0;
}