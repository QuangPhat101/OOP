#include "Square.h"
#include <format>
using std::format;

Square::Square() {
  // Do nothing
}

Square::Square(float side) { this->_side = side; }

float Square::area() { return _side * _side; }

float Square::perimeter() { return _side * 4; }

std::string Square::toString() {
  return format("Vuông: Cạnh={}, Chu vi={}, Diện tích={}", _side, perimeter(),
                area());
}