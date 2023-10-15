#include "book.cpp"
#include "person.cpp"

#include <iostream>

using namespace std;

void Solve() {
  vector<Book*> vb;
  for (int i = 0; i < 100; i++) vb.push_back(new Book);

  vector<Person*> person;
  vector<Children*> children;

  for (int i = 0; i < 3; i++) {
    Children* p = new Children;
    for (Book* b : vb) if (rand() % 100 >= 80) p->getVB().push_back(*b);

    children.push_back(p);
    person.push_back(p);
  }
  vector<Adult*> adult;
  for (int i = 0; i < 6; i++) {
    Adult* a = new Adult;
    for (Book* b : vb) if (rand() % 10000 >= 9999) a->getVB().push_back(*b);

    adult.push_back(a);
    person.push_back(a);
  }

  // Person::sortPersonAge(person);
  // for (Person* p : person) p->display();

  // vector<int> ages = Person::getListAge(person);
  // cout << "Ages: " << endl;
  // for (int i : ages) cout << i << " ";
  Person::getMaxBookBorrowed(person, vb);
}

int main() {
  srand(time(NULL));
  Solve();

  return 0;
}