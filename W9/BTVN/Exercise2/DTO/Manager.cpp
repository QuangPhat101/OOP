#include "Manager.h"

int Manager::salary() {
  return _baseSalary + (_employeeCount * _paymentPerEmployee);
}
int Manager::getEmployeeCount() { return _employeeCount; }
void Manager::setEmployeeCount(int employeeCount) {
  _employeeCount = employeeCount;
}
int Manager::getPaymentPerEmployee() { return _paymentPerEmployee; }
void Manager::setPaymentPerEmployee(int paymentPerEmployee) {
  _paymentPerEmployee = paymentPerEmployee;
}
int Manager::getBaseSalary() { return _baseSalary; }
void Manager::setBaseSalary(int baseSalary) { _baseSalary = baseSalary; }
Manager::Manager() {
  _employeeCount = 0;
  _paymentPerEmployee = 0;
  _baseSalary = 0;
}
string Manager::toString() { return "Manager"; }