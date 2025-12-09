#include "DailyEmployee.h"
#include "Employee.h"
#include "Manager.h"
#include "ProductEmployee.h"

#include <format>
#include <iostream>
#include <vector>

using std::cout;
using std::format;
using std::string;
using std::vector;

int main() {
  vector<Employee *> employees = {new ProductEmployee("John", 10, 100),
                                  new Manager("Jack", 2000, 10, 500),
                                  new ProductEmployee("Alicia", 20, 550),
                                  new DailyEmployee("Batistile", 10, 200)};
  for (auto employee : employees) {
    cout << format("{}: Salary={}\n", employee->name(), employee->salary());
  }
  for (auto &employee : employees) {
    delete employee;
  }
  return 0;
}