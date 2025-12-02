#include "Rectangle.h"

Rectangle::Rectangle() {
  // Do nothing
}

float Rectangle::width() { return _width; }

float Rectangle::height() { return _height; }

Rectangle::Rectangle(float width, float height) {
  this->_width = width;
  this->_height = height;
}

float Rectangle::area() {
  float s = _width * _height;
  return s;
}

float Rectangle::perimeter() {
  float s = 2 * (_width + _height);
  return s;
}
