#pragma once
#include <string>
using std::string;

class IShape {
public:
  virtual std::string toString() const = 0;
  virtual ~IShape() = default;
};