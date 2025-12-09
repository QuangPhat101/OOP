#pragma once
#include "IShape.h"
#include <format>
using std::format;

class Square : public IShape {
private:
  double _side;

public:
  Square(double side);
  std::string toString() const override;
  ~Square() override;

public:
  int side() const;
};
