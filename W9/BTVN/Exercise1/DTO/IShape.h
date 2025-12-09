#ifndef _ISHAPE_H_
#define _ISHAPE_H_
#include "Object.h"
#include <format>
#include <string>
using std::format;
using std::string;

class IShape : public Object {
public:
  virtual float area() = 0;
  virtual float perimeter() = 0;

public:
  string toString() override;
};

#endif