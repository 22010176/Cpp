#include <iostream>
#include <string>

using namespace std;

class Product {
private:
  string code;
  float price;
public:
  Product() : code("No code"), price(0.0) {}
  Product(string c, double pr) : code(c), price(pr) {
    // cout << "Base Constructor\n";
  }
  ~Product() {
    // cout << "Base Destructor\n";
  }
  virtual void show() const;
};

class Book : public Product {
private:
  string title, author;
public:
  Book() : title("No title"), author("No author") {}
  Book(string c, double pr, string tle, string au) : Product(c, pr), title(tle), author(au) {
    // cout << "Derived Constructor\n";
  }
  ~Book() {
    // cout << "Derived Destructors\n";
  }
  void display() const { cout << "Book Title: " << title << "\nAuthor: " << author << endl; }
  void show() const;
};

void Product::show() const { cout << "Product code: " << code << "\nPrice: " << price << endl; }
void Book::show() const { cout << "Book Title: " << title << "\nAuthor: " << author << endl; }

void _a() {
  int a;
  Product* ptr;
  cin >> a;

  if (a == 1) ptr = new Product("A", 20);
  else ptr = new Book("Afsd", 25.5, "Asd", "Asd");

  ptr->show();
}
void _b() {
  Book b("AB20", 9.2, "C++", "S M");
  Product c;

  Product* p = &b;
  Product& r = b;

  p->show();
  r.show();
}
int main() {
  _a();
  return 0;
}