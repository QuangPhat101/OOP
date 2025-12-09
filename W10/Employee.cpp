#include "Employee.h"

string Employee::name() { return this->_name; }

Employee::Employee() { this->_name = ""; }

Employee::Employee(string name) { this->_name = name; }

Employee::~Employee() {
  // Do nothing
}