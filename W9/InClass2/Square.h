#ifndef _SQUARE_H
#define _SQUARE_H

#include "IShape.h"

class Square : public IShape {
private:
  float _side;

public:
  float side();

public:
  Square();
  Square(float side);

public:
  float area() override;
  float perimeter() override;
};

#endif