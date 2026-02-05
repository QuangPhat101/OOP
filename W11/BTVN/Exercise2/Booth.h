#ifndef BOOTH_H
#define BOOTH_H

#include "Utils.h"
#include <iostream>
#include <string>

using namespace std;

class Booth {
protected:
  string id;
  double area;
  double baseRate;

public:
  Booth(string id, double area, double baseRate)
      : id(id), area(area), baseRate(baseRate) {}
  virtual ~Booth() {}

public:
  virtual long long calculateRent() const = 0;
  virtual string toString() const = 0;
  long long getRent() const { return calculateRent(); }
  long long getBaseRent() const { return (long long)(area * baseRate); }
};

#endif