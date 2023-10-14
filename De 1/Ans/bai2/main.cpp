#include <vector>
#include <iostream>

#include "Children.cpp"
#include "Adult.cpp"
#include "Book.cpp"

int main() {
  vector<Book> books(5);
  books[0] = Book("A", "A", 1);
  books[1] = Book("B", "B", 2);
  books[2] = Book("C", "C", 3);
  books[3] = Book("D", "D", 4);
  books[4] = Book("E", "E", 5);

  Children children[3]{
    Children("A", 10, "HN", { books[0], books[1] }),
    Children("B", 20, "HN", { books[2], books[4], books[3] }),
    Children("C", 30, "HN", { books[3], books[4] })
  };

  Adult adults[2]{
    Adult("A", 1, "HN", { books[0], books[1] }),
    Adult("B", 2, "HN", { books[0], books[1], books[2], books[3], books[4] })
  };

  vector<Person*> persons{ &children[0], &children[1], &children[2], &adults[0], &adults[1] };

  cout << "Danh sach tuoi" << endl;
  for (auto v : Person::getListAge(persons)) cout << v << " ";

  cout << endl << "Sach muon nhieu nhat" << endl;
  for (auto v : Person::getMaxBookBorrowed(persons, books)) v.display();

  cout << "Sap xep theo tuoi" << endl;
  Person::sortPersonAge(persons);
  for (auto v : persons) v->display();
}
