#ifndef _DAILYEMPLOYEE_H_
#define _DAILYEMPLOYEE_H_

#include "Employee.h"
class DailyEmployee : public Employee {
private:
  int _daysCount;
  int _paidPerDay;

public:
  int salary() override;
  DailyEmployee();
  DailyEmployee(string name, int daysCount, int paidPerDay);
  ~DailyEmployee() override;
};

#endif