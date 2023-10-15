#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Person {
private:
  string name, add, tel, sex;
  int age;
public:
  Person() : name(to_string(rand())), add(rand() % 100 >= 50 ? "HN" : to_string(rand())), tel(to_string(rand())), sex(rand() % 2 ? "Nam" : "Nu"), age(rand() % 20 + 20) {}
  Person(string name, int age, string add, string tel, string sex) : name{ name }, age{ age }, add{ add }, tel{ tel }, sex{ sex } {}

  string getName() { return name; }
  int getAge() { return age; }
  string getAdd() { return add; }
  string getTel() { return tel; }
  string getSex() { return sex; }

  virtual void display() { cout << (*this) << endl; }
  virtual long salary() = 0;

  static vector<Person*> findPerson(vector<Person*> p) {
    vector<Person*> res;
    for (Person*& person : p) if (person->getAdd() == "HN") res.push_back(person);
    return  res;
  }
  friend ostream& operator<< (ostream& out, Person& p) {
    out << "Name: " << p.getName() << endl;
    out << "Age: " << p.getAge() << endl;
    out << "Sex: " << p.getSex() << endl;
    out << "Add: " << p.getAdd() << endl;
    out << "Tel: " << p.getTel() << endl;
    return out;
  }
};

class EmployeePT : public Person {
private:
  int hour;
  long money;
public:
  EmployeePT() : Person(), hour(rand() % 24), money(rand() % 1000) {}
  EmployeePT(string name, int age, string add, string tel, string sex, int hour, long money) : Person(name, age, add, tel, sex), hour{ hour }, money{ money } {}

  int getHour() { return hour; }
  long getMoney() { return money; }
  void display() { cout << *this << endl; }
  long salary() { return hour * money; }

  static vector<EmployeePT> getMaxSalary(vector<EmployeePT>& pt) {
    vector<EmployeePT> res = pt;
    sort(res.begin(), res.end(), [](EmployeePT& a, EmployeePT& b) {return a.salary() > b.salary();});
    return res;
  }
  friend ostream& operator<< (ostream& out, EmployeePT& pt) {
    out << (Person&)pt;
    out << "Hour: " << pt.getHour() << endl;
    out << "Money: " << pt.getMoney() << endl;
    out << "Salary: " << pt.salary() << endl;
    return out;
  }
};
class EmployeeFT : public Person {
private:
  int day;
  long money;
public:
  EmployeeFT() : Person(), day(rand() % 24), money(rand() % 1000) {}
  EmployeeFT(string name, int age, string add, string tel, string sex, int day, long money) : Person(name, age, add, tel, sex), day{ day }, money{ money } {}

  int getDay() { return day; }
  long getMoney() { return money; }
  void display() { cout << *this << endl; }
  long salary() { return day * money; }
  static vector<EmployeeFT> getMaxSalary(vector<EmployeeFT> pt) {
    vector<EmployeeFT> res = pt;
    sort(res.begin(), res.end(), [](EmployeeFT& a, EmployeeFT& b) {return a.salary() > b.salary();});
    return res;
  }
  friend ostream& operator<< (ostream& out, EmployeeFT& ft) {
    out << (Person&)ft;
    out << "Day: " << ft.getDay() << endl;
    out << "Money: " << ft.getMoney() << endl;
    out << "Salary: " << ft.salary() << endl;
    return out;
  }
};

#endif


