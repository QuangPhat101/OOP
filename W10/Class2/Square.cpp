#include "Square.h"
Square::Square(double side) : _side(side) {
  // Do nothing
}
int Square::side() const { return this->_side; }
Square::~Square() {
  // Do nothing
}
std::string Square::toString() const {
  return format("Square side={}", this->_side);
}