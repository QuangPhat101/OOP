#ifndef _RECTANGLEDECORATOR_H_
#define _RECTANGLEDECORATOR_H_

#include "Rectangle.h"
#include "ShapeDecorator.h"
#include <iostream>
using std::cout;

class RectangleDecorator : public ShapeDecorator, public Rectangle {
public:
  RectangleDecorator();
  RectangleDecorator(IShape *shape, int filltype, char symbol)
      : ShapeDecorator(shape, filltype, symbol) {
    Rectangle *rect = dynamic_cast<Rectangle *>(shape);

    if (rect != nullptr) {
      this->_width = rect->width();
      this->_height = rect->height();
    };
  }
  void draw() const override;
};
#endif