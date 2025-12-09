#ifndef _DAILYEMPLOYEE_H_
#define _DAILYEMPLOYEE_H_
#include "Employee.h"
#include <iostream>
#include <string>
using std::string;
using std::to_string;

class DailyEmployee : public Employee {
private:
  int _dayCount;
  int _paymentPerDay;

public:
  int getDayCount();
  void setDayCount(int dayCount);

  int getPaymentPerDay();
  void setPaymentPerDay(int paymentPerDay);

public:
  int salary() override;
  DailyEmployee();
  string toString() override;
};

#endif