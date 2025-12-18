#ifndef _ISHAPE_H_
#define _ISHAPE_H_

#include <iostream>
#include <string>
using std::string;

class IShape { // interface
public:
  virtual ~IShape() = default;
  virtual std::string toString() const = 0;
};

#endif