#ifndef _SQUARE_H_
#define _SQUARE_H_

#include "IShape.h"
#include <format>
#include <iostream>
#include <string>
using std::format;
using std::string;

class Square : public IShape {
protected:
  double _size;

public:
  Square();
  Square(double size);
  ~Square();

public:
  double size();
  void setSize(double size);

public:
  double area();
  std::string toString() const override;
};

#endif