#include "Rectangle.h"

Rectangle::Rectangle(double width, double height) {
  this->_width = width;
  this->_height = height;
}
std::string Rectangle::toString() const {
  return format("Rectangle width={}, height={}", this->_width, this->_height);
}
Rectangle::~Rectangle() {
  // do nothing
}
int Rectangle::width() const { return this->_width; }
int Rectangle::height() const { return this->_height; }