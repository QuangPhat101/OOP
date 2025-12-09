#ifndef _CIRCLE_H
#define _CIRCLE_H
#include "IShape.h"

class Circle : public IShape {
private:
  float _radius;

public:
  Circle();
  Circle(float radius);

public:
  float radius();
  void setRadius(float radius);

public:
  float area() override;
  float perimeter() override;
  string toString() override;
};

#endif