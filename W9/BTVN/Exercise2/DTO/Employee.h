#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include "Object.h"
#include <iostream>
#include <string>
using std::string;

class Employee : public Object {
public:
  virtual int salary() = 0;
  string toString() override = 0;
};
#endif