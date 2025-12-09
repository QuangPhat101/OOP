#include "Rectangle.h"

Rectangle::Rectangle() {
  // Do nothing
}

float Rectangle::width() { return _width; }

float Rectangle::height() { return _height; }

void Rectangle::setWidth(float width) { this->_width = width; }
void Rectangle::setHeight(float height) { this->_height = height; }

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
string Rectangle::toString() {
  return format("Rectangle: width = {}, height = {}, area = {}, perimeter = {}",
                _width, _height, area(), perimeter());
}