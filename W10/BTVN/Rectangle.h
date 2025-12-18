#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "IShape.h"
#include <format>
#include <iostream>
#include <string>
using std::format;
using std::string;

class Rectangle : public IShape {
protected:
  double _width;
  double _height;

public:
  Rectangle();
  Rectangle(double width, double height);
  ~Rectangle();

public:
  double width();
  double height();
  void setWidth(double width);
  void setHeight(double height);

public:
  double area();
  std::string toString() const override;
};
#endif