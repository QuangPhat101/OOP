#pragma once
#include "IShape.h"

class Decorator {
protected:
  IShape *_shape;
  bool _isFilled;
  char _symbol;

public:
  virtual void draw() = 0;
  Decorator();
  virtual ~Decorator();
  Decorator(IShape *shape, bool isFilled, char symbol);

public:
  IShape *getShape() const;
  bool isFilled() const;
  char getSymbol() const;
};