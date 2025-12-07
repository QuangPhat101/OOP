#include "Circle.h"

Circle::Circle() {
  // Do nothing
}
Circle::Circle(float radius) { this->_radius = radius; }

float Circle::area() {
  float s = 3.14 * _radius * _radius;
  return s;
}

float Circle::perimeter() {
  float s = 2 * 3.14 * _radius;
  return s;
}

float Circle::radius() { return _radius; }