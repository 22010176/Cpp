#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#include "Book.cpp"

using namespace std;

class Person {
private:
  int age;
  string name, add;
  vector<Book> vb;
  bool _f(Person& a, Person& b) { return a > b; }
  // bool _f(Person* a, Person* b) {
  //   Person _a = *a, _b = *b;
  //   return _a > _b;
  // }

public:
  Person() : age(rand() % 100), vb(vector<Book>{}), name(to_string(rand())), add(to_string(rand())) {};
  Person(string name, int age, string add, vector<Book> vb);

  string& getName() { return name; }
  int getAge() { return age; }
  string& getAdd() { return add; }
  vector<Book>& getVB() { return vb; }

  virtual long moneyPay() { return 0; };
  void display();

  static void sortPersonAge(vector<Person>& vt);
  static vector<int> getListAge(vector<Person*>& vt);
  static vector<Book> getMaxBookBorrowed(vector<Person*>& vp, vector<Book*>& vB);

  bool operator>(Person& other) { return this->age > other.getAge(); }
  bool operator<(Person& other) { return this->age < other.getAge(); }
  bool operator==(Person& other) { return this->age == other.getAge(); }
  friend ostream& operator<<(ostream& out, Person& other) {

  }
};

void Person::display() {
  cout << endl;
  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
  cout << "Add: " << add << endl;

  cout << "List Book Borrowed: " << endl;
  for (int i = 0;i < vb.size();i++) {
    cout << "Cuon sach " << i + 1 << ": ";
    vb.at(i).display();
    cout << endl;
  }
}

void Person::sortPersonAge(vector<Person>& vt) {

  // sort(vt.begin(), vt.end(), _f);
}
vector<int> Person::getListAge(vector<Person*>& vt) {
  set<int> ages;
  for (Person* p : vt) ages.insert(p->getAge());
  return vector<int>(ages.begin(), ages.end());
}
vector<Book> Person::getMaxBookBorrowed(vector<Person*>& vp, vector<Book*>& vB) { return vector<Book>{}; }

#endif

int main() {
  srand(time(NULL));

  vector<Person> p;
  for (int i = 0; i < 10; i++) {
    // Person a;
    // for (int j = 0; j < rand() % 10; j++) {
    //   Book b;
    //   a.getVB().push_back(b);
    // }
    // p.push_back(&a);
  }
  // p.at(0)->display();
  // Person::sortPersonAge(p);



}