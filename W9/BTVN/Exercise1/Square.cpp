#include "Square.h"

Square::Square() { /*Do nothing*/ }

float Square::side() { return _side; }

Square::Square(float side) { this->_side = side; }

float Square::area() {
  float s = _side * _side;
  return s;
}

float Square::perimeter() {
  float s = 4 * _side;
  return s;
}
