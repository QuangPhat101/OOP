#ifndef _TRIANGLE_H_
#define _TRIANGLE_H

#include "IShape.h"

class Triangle : public IShape {
private:
  float _a;
  float _b;
  float _c;

public:
  Triangle();
  Triangle(float a, float b, float c);

public:
  float a();
  float b();
  float c();

public:
  float area() override;
  float perimeter() override;
};
#endif