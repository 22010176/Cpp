#ifndef _BOOK_H_
#define _BOOK_H_

#include <string>
#include <iostream>

using namespace std;

class Book {
private:
  string nameBook, nameAuthor;
  int numberBook;
public:
  Book() : numberBook{ rand() % 1000 }, nameBook{ to_string(rand()) }, nameAuthor{ to_string(rand()) } {};
  Book(string nameBook, string nameAuthor, int numberBookk) : nameBook{ nameBook }, nameAuthor{ nameAuthor }, numberBook{ numberBook } {}

  string getNameBook() { return nameBook; }
  string getNameAuthor() { return nameAuthor; }
  int getNumberBook() { return numberBook; }

  void display() {
    cout << endl;
    cout << "Ten sach: " << nameBook << endl;
    cout << "Ten tac gia: " << nameAuthor << endl;
    cout << "Ma so sach: " << numberBook << endl;
  }
};

#endif