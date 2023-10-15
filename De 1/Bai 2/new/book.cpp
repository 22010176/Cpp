#ifndef _BOOK_H_
#define _BOOK_H_

#include <string>

using namespace std;

class Book {
private:
  string nameBook, nameAuthor;
  int numberBook;
public:
  Book() {}
  Book(string nameBook, string nameAuthor, int numberBook) : nameBook(nameBook), nameAuthor(nameAuthor), numberBook(numberBook) {}
  string getNameBook() { return nameBook; }
  string getNameAuthor() { return nameAuthor; }
  int getNumberBook() { return numberBook; }
};

#endif  