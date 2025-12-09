#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
#include "IShape.h"

class Rectangle : public IShape {
private:
  float _width;
  float _height;

public:
  float width();
  float height();
  void setWidth(float width);
  void setHeight(float height);

public:
  Rectangle();
  Rectangle(float width, float height);

public:
  float area() override;
  float perimeter() override;
  string toString() override;
};

#endif