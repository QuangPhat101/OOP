#pragma once
#include "IShape.h"
#include <format>
using std::format;

class Rectangle : public IShape {
private:
  double _width;
  double _height;

public:
  Rectangle(double width, double height);
  std::string toString() const override;
  ~Rectangle() override;

public:
  int width() const;
  int height() const;
};