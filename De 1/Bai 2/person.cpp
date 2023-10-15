#ifndef _PERSON_H_
#define _PERSON_H_

#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <iostream>

#include "Book.cpp"

using namespace std;

class Person {
private:
  string add, name;
  vector<Book> vb;
  int age;

public:
  Person() : add{ to_string(rand()) }, name{ to_string(rand()) }, age{ rand() % 100 } {}
  Person(string name, int age, string add, vector<Book> vb) : name(name), age(age), add(add), vb(vb) {};

  string getName() { return name; }
  string getAdd() { return add; }
  vector<Book>& getVB() { return vb; }
  int getAge() { return age; }

  virtual long moneyPay() = 0;
  virtual void display() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Add: " << add << endl;
    cout << endl << "List Book Borrowed" << endl;


    for (int i = 0; i < vb.size();i++) {
      cout << "Cuon sach thu " << i + 1 << ": " << endl;
      vb.at(i).display();
      cout << endl;
    }
    cout << endl;
  }

  static void sortPersonAge(vector<Person*>& vt) {
    sort(vt.begin(), vt.end(), [](Person* a, Person* b) {return a->getAge() > b->getAge();});
  }
  static vector<int> getListAge(vector<Person*> vt) {
    set<int> ages;
    for (Person* p : vt) ages.insert(p->getAge());
    return vector<int>(ages.begin(), ages.end());
  }
  static vector<Book> getMaxBookBorrowed(vector<Person*> vp, vector<Book*> vB) {
    vector<_E> e;
    for (Book* b : vB) e.push_back(_E(*b));
    for (Person* p : vp) {
      vector<Book>& b = p->getVB();
      for (Book& _b : b) ++find_if(e.begin(), e.end(), [_b](const _E& a) {return a._b.getNameBook() == _b.getNameBook() && a._b.getNameAuthor() == _b.getNameAuthor();})[0];
    }
    sort(e.begin(), e.end(), [](_E& a, _E& b) {return a.times > b.times;});

    vector<Book> b;
    for (_E& _e : e) b.push_back(_e._b);

    return b;
  }
};

class Adult : public Person {
public:
  Adult() : Person() {}
  Adult(string name, int age, string add, vector<Book> vb) : Person(name, age, add, vb) {}
  virtual long moneyPay() { return getVB().size() * 10000; }
  void display() {
    cout << "Adult" << endl;
    Person::display();
  }
};
class Children : public Person {
public:
  Children() : Person() {}
  Children(string name, int age, string add, vector<Book> vb) : Person(name, age, add, vb) {}
  virtual long moneyPay() { return getVB().size() * 5000; }
  void display() {
    cout << "Children" << endl;
    Person::display();
  }
};

#endif