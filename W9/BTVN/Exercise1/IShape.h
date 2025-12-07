#ifndef _ISHAPE_H_
#define _ISHAPE_H_
#include <string>
using std::string;

class IShape { 
public:
  virtual float area() = 0;
  virtual float perimeter() = 0;

public:
  virtual std::string toString() = 0;
};

#endif