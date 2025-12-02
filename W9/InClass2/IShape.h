#ifndef _ISHAPE_H_
#define _ISHAPE_H_

#include <iostream>
#include <string>
using namespace std;

class IShape { // abstract class => interface
public:
  virtual float area() = 0;
  virtual float perimeter() = 0;
};

#endif