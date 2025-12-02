#include "Triangle.h"
#include <cmath>
Triangle::Triangle() {
  // Do nothing
}
Triangle::Triangle(float a, float b, float c) {
  this->_a = a;
  this->_b = b;
  this->_c = c;
}

float Triangle::area() {
  float p = (_a + _b + _c) / 2;
  float s = sqrt(p * (p - _a) * (p - _b) * (p - _c));
  return s;
}
float Triangle::perimeter() {
  float s = _a + _b + _c;
  return s;
}

float Triangle::a() { return _a; }
float Triangle::b() { return _b; }
float Triangle::c() { return _c; }