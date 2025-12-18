#ifndef _SHAPEDECORATOR_H_
#define _SHAPEDECORATOR_H_

#include "IShape.h"
class ShapeDecorator : public IShape {
protected:
  int _fillType;
  char _symbol;
  IShape *_shape;

public:
  ShapeDecorator() {};
  ShapeDecorator(IShape *shape, int fillType, char symbol)
      : _shape(shape), _fillType(fillType), _symbol(symbol) {}
  virtual void draw() const = 0;
  std::string toString() const override { return ""; };
  virtual ~ShapeDecorator() = default;
};

#endif