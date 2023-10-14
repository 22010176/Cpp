#include <iostream>
#include <cstdlib> // need for exit(EXIT_FAILER) func

#include "Rectangle.h"

Rectangle::Rectangle() { width = height = 0; }
void Rectangle::setWidth(double w) {
  if (w > 0) width = w;
  else {
    std::cout << "Invalid width\n";
    exit(EXIT_FAILURE);
  }
}
void Rectangle::setHeight(double h) {
  if (h > 0) height = h;
  else {
    std::cout << "Invalid height\n";
    exit(EXIT_FAILURE);
  }
}

