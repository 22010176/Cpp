#pragma once
#include <iostream>
using namespace std;

class Book
{
private:
  string nameBook;
  string nameAuthor;
  int numberBook;

public:
  Book() {}
  Book(string nameBook, string nameAuthor, int numberBook) {
    this->nameBook = nameBook;
    this->nameAuthor = nameAuthor;
    this->numberBook = numberBook;
  }

  void display() {
    cout << "Name Book: " << this->nameBook << endl;
    cout << "Name Author: " << this->nameAuthor << endl;
    cout << "Number Book: " << this->numberBook << endl;
  }

  int getNumberBook() { return this->numberBook; }
  string getNameBook() { return this->nameBook; }
  string getNameAuthor() { return this->nameAuthor; }
};
