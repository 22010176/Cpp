#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <cstdint>

using namespace std;

class Book {
private:
  string nameBook, nameAuthor;
  int numberBook;
public:
  Book() {
    nameBook = to_string(rand() % INT32_MAX);
    nameAuthor = to_string(rand() % INT32_MAX);
    numberBook = rand() % INT32_MAX;
  }
  Book(string b_name, string a_name, int books) : numberBook{ books }, nameAuthor{ a_name }, nameBook{ b_name } {}

  string getNameBook() const { return nameBook; }
  string getNameAuthor() const { return nameAuthor; }
  int getNumberBook() const { return numberBook; }

  void display() const {
    cout << "Ten sach: " << nameBook << endl;
    cout << "Ten tac gia: " << nameAuthor << endl;
    cout << "Ma so sach: " << numberBook << endl;
  }
};

class Person {
private:
  int age;
  string name, add;
  vector<Book> vb;
  static bool func(const Person& a, const Person& b) { return a.getAge() > b.getAge(); }
public:
  Person() {
    age = rand() % 100;
    name = string(to_string(rand() % INT32_MAX));
    add = string(to_string(rand() % INT32_MAX));
  }
  Person(string name, int age, string add, vector<Book> vb) : name(name), age(age), add(add), vb(vb) {  }

  string getName() const { return name; }
  int getAge() const { return age; }
  string getAdd() const { return add; }
  vector<Book> getVB() const { return vb; }

  virtual long moneyPay() const = 0;
  void display() const {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Add: " << add << endl;
    cout << "List Book Borrowed" << endl;

    for (int i = 0; i < vb.size();i++) {
      const Book& b = vb.at(i);

      cout << "Cuon sach " << i + 1 << ":" << endl;
      cout << "Name Book: " << b.getNameBook() << endl;
      cout << "Name Author: " << b.getNameAuthor() << endl;
      cout << "Number Book: " << b.getNumberBook() << endl;
    }
  }
  static void sortPersonAge(const vector<Person>& vt) { sort(vt.begin(), vt.end(), Person::func); }
  static vector<int> getListAge(vector<Person*> vt) {
    set<int> ages;
    for (const Person* p : vt) ages.insert(p->getAge());

    vector<int> res;
    for (const int a : ages) res.push_back(a);
    return res;
  }
  static vector<Book> getMaxBookBorrowed(vector<Person> vp, vector<Book> vB) {
    return vector<Book> {};
  }
};

class Children : public Person {
public:
  Children() : Person() {}
  Children(string name, int age, string add, vector<Book> vb) : Person{ name,age,add,vb } {}
  virtual long moneyPay() const { return Person::getVB().size() * 5000; }
  void display() const {
    cout << "Doc gia Tre em." << endl;
    Person::display();
  }
};

class Adult : public Person {
public:
  Adult() : Person() {}
  Adult(string name, int age, string add, vector<Book> vb) : Person{ name,age,add,vb } {}
  virtual long moneyPay() const { return Person::getVB().size() * 10000; }
  void display() {
    cout << "Doc gia Nguoi lon" << endl;
    Person::display();
  }
};

void _test() {
  vector<Book> b;
  vector<Children> c;
  vector<Adult> a;

  vector<Person*> p;
  for (int i = 0; i < 1000;i++) {
    Person* _p;
    if (rand() % 2 == 0) {
      _p = new Children;
      c.push_back(*static_cast<Children*>(_p));
    }
    else {
      _p = new Adult;
      a.push_back(*static_cast<Adult*>(_p));
    }
    p.push_back(_p);
  }

  vector<int> res = Person::getListAge(p);
  for (auto i : res) cout << i << endl;

}

int main() {
  srand(time(NULL));
  return 0;
}