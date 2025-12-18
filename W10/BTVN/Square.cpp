#include "Square.h"

Square::Square() {
  // Do nothing
}
Square::Square(double size) { this->_size = size; }
Square::~Square() {
  // Do nothing
}

double Square::size() { return this->_size; }
void Square::setSize(double size) { this->_size = size; }

double Square::area() { return _size * _size; }
std::string Square::toString() const {
  return format("Square Size = {}", this->_size);
}