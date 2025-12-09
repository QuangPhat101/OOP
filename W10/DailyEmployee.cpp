#include "DailyEmployee.h"

int DailyEmployee::salary() { return _daysCount * _paidPerDay; }
DailyEmployee::DailyEmployee() {
  _daysCount = 0;
  _paidPerDay = 0;
}
DailyEmployee::DailyEmployee(string name, int daysCount, int paidPerDay)
    : Employee(name) {
  _daysCount = daysCount;
  _paidPerDay = paidPerDay;
}
DailyEmployee::~DailyEmployee() {
  // Do nothing
}