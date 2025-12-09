#pragma once
#include "Decorator.h"
#include "Square.h"
#include <iostream>

class SquareDecorator : public Decorator {
public:
  void draw() override;
  SquareDecorator();
  ~SquareDecorator() override;
  SquareDecorator(IShape *shape, bool isFilled, char symbol);
};