#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

class Rectangle {
private:
  double width, height;
public:
  Rectangle(); // Constructor

  void setWidth(double w);
  void setHeight(double h);

  double getWidth() const { return width; }
  double getHeight() const { return height; }
  double getArea() const { return width * height; }
};

#endif