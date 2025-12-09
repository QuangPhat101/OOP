#pragma once
#include "Decorator.h"
#include "Rectangle.h"
#include <iostream>
using std::string;

class RectangleDecorator : public Decorator {
public:
  void draw() override;
  RectangleDecorator();
  ~RectangleDecorator() override;
  RectangleDecorator(IShape *shape, bool isFilled, char symbol);
};
