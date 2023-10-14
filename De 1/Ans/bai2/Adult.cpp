#pragma once
#include "Person.cpp"
class Adult : public Person {
public:
  Adult() {}
  Adult(string name, int age, string add, vector<Book> vb) : Person(name, age, add, vb) {}
  long moneyPay() { return this->getVB().size() * 10000; }
  void display() {
    cout << "Adult!" << endl;
    Person::display();
  }
};
