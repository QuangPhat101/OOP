#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>
using std::string;

class Employee {
private:
  string _name;

public:
  string name();
  virtual int salary() = 0;
  Employee();
  Employee(string name);
  virtual ~Employee();
};

#endif