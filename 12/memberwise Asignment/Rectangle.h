#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

class Rectangle {
private:
  double width, length;
public:
  Rectangle(double w, double len) { width = w, length = len; }
  void setWidth(double w) { width = w; }
  void setLength(double len) { length = len; }
  double getWidth() const { return width; }
  double getLength() const { return length; }
};

#endif