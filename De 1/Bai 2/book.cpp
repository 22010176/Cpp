#ifndef _BOOK_H_
#define _BOOK_H_

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


struct _E {
  Book _b; int times;

  _E(Book b, int t = 0) : _b{ b }, times{ t } {}

  _E& operator++() {
    times++;
    return *this;
  }
  _E operator++(int i) {
    _E a = *this; ++a;
    return a;
  }
  void Print() { cout << _b << ": " << times << endl; }
};

class Book {
private:
  string nameBook, nameAuthor;
  int numberBook;
public:
  Book() :nameBook{ to_string(rand()) }, nameAuthor{ to_string(rand()) }, numberBook{ rand() % 100 } {}
  Book(string nameBook, string nameAuthor, int numberBook) : nameBook(nameBook), nameAuthor(nameAuthor), numberBook(numberBook) {}
  string getNameBook() const { return nameBook; }
  string getNameAuthor() const { return nameAuthor; }
  int getNumberBook() const { return numberBook; }
  void display() const {
    cout << "Ten sach: " << nameBook << endl;
    cout << "Ten tac gia: " << nameAuthor << endl;
    cout << "Ma so sach: " << numberBook << endl;
  }
  bool operator==(const Book* other) const { return other->nameBook == nameBook && other->nameAuthor == nameAuthor; }
  friend ostream& operator<< (ostream& out, Book& b);
};

ostream& operator<< (ostream& out, Book& b) {
  out << setw(10) << b.getNameBook();
  return out;
}
#endif  