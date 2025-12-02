#include "Rectangle.h"
#include <format>
using std::format;

Rectangle::Rectangle() {
  // Do nothing
}

Rectangle::Rectangle(float width, float height) {
  this->_width = width;
  this->_height = height;
}

float Rectangle::area() { return _width * _height; }

float Rectangle::perimeter() { return (_width + _height) * 2; }

std::string Rectangle::toString() {
  return format("Chữ nhật: A={}, B={}, Chu vi={}, Diện tích={}", _width,
                _height, perimeter(), area());
}