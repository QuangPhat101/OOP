#include "Square.h"

Square::Square() { /*Do nothing*/ }

float Square::side() { return _side; }

Square::Square(float side) { this->_side = side; }
void Square::setSide(float side) { this->_side = side; }
float Square::area() {
  float s = _side * _side;
  return s;
}

float Square::perimeter() {
  float s = 4 * _side;
  return s;
}
string Square::toString() {
  return format("Square: side = {}, area = {}, perimeter = {}", _side, area(),
                perimeter());
}
