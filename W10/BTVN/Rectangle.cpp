#include "Rectangle.h"

Rectangle::Rectangle() {
  // Do nothing
}
Rectangle::Rectangle(double width, double height) {
  this->_width = width;
  this->_height = height;
}
Rectangle::~Rectangle() {
  // Do nothing
}
double Rectangle::width() { return this->_width; }
double Rectangle::height() { return this->_height; }
void Rectangle::setWidth(double width) { this->_width = width; }
void Rectangle::setHeight(double height) { this->_height = height; }
double Rectangle::area() { return _width * _height; }
std::string Rectangle::toString() const {
  return format("Rectangle Width = {}, Height = {}", this->_width,
                this->_height);
}