#ifndef _SquareDECORATOR_H_
#define _SquareDECORATOR_H_

#include "ShapeDecorator.h"
#include "Square.h"
#include <iostream>
using std::cout;

class SquareDecorator : public ShapeDecorator, public Square {
public:
  SquareDecorator();
  SquareDecorator(IShape *shape, int filltype, char symbol)
      : ShapeDecorator(shape, filltype, symbol) {
    Square *square = dynamic_cast<Square *>(shape);
    this->_size = square->size();
  };
  void draw() const override;
};
#endif