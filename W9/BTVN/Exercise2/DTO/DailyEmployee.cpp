#include "DailyEmployee.h"

int DailyEmployee::salary() { return _dayCount * _paymentPerDay; }
int DailyEmployee::getDayCount() { return _dayCount; }
void DailyEmployee::setDayCount(int dayCount) { _dayCount = dayCount; }
int DailyEmployee::getPaymentPerDay() { return _paymentPerDay; }
void DailyEmployee::setPaymentPerDay(int paymentPerDay) {
  _paymentPerDay = paymentPerDay;
}
DailyEmployee::DailyEmployee() {
  // Do nothing
}
string DailyEmployee::toString() { return "DailyEmployee"; }