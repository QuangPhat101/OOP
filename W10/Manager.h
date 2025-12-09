#ifndef _MANAGER_H_
#define _MANAGER_H_
#include "Employee.h"

class Manager : public Employee {
private:
  int _baseSalary;
  int _subsidiariesCount;
  int _paidPerSubsidiary;

public:
  int salary() override;
  Manager();
  Manager(string name, int baseSalary, int subsidiariesCount,
          int paidPerSubsidiary);
  ~Manager() override;
};

#endif