#ifndef _MANAGER_H_
#define _MANAGER_H_
#include "Employee.h"
#include <iostream>
#include <string>
using std::string;
using std::to_string;

class Manager : public Employee {
private:
  int _employeeCount;
  int _paymentPerEmployee;
  int _baseSalary;

public:
  int getEmployeeCount();
  void setEmployeeCount(int employeeCount);
  int getPaymentPerEmployee();
  void setPaymentPerEmployee(int paymentPerEmployee);
  int getBaseSalary();
  void setBaseSalary(int baseSalary);

public:
  Manager();
  string toString() override;
  int salary() override;
};

#endif