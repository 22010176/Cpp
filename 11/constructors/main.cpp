#include <iostream>
#include "Rectangle.h"

// g++ main.cpp Rectangle.cpp -o main; ./main; del ./main.exe

void Print(const Rectangle& r) {
  std::cout << "The rectangle's data: " << std::endl;
  std::cout << "Width: " << r.getWidth() << std::endl;
  std::cout << "Height: " << r.getHeight() << std::endl;
  std::cout << "Area: " << r.getArea() << std::endl;
}

int main() {
  Rectangle r;
  Rectangle* p;

  p = &r; // assign address to p


  p->setHeight(14.5);
  p->setWidth(10);

  Print(*p);


  Rectangle* rPtr = new Rectangle;
  Print(*rPtr);

  delete rPtr;
  return 0;
}