#include "Manager.h"

int Manager::salary() {
  return _baseSalary + _subsidiariesCount * _paidPerSubsidiary;
}
Manager::Manager() {
  _baseSalary = 0;
  _subsidiariesCount = 0;
  _paidPerSubsidiary = 0;
}
Manager::Manager(string name, int baseSalary, int subsidiariesCount,
                 int paidPerSubsidiary)
    : Employee(name) {
  _baseSalary = baseSalary;
  _subsidiariesCount = subsidiariesCount;
  _paidPerSubsidiary = paidPerSubsidiary;
}
Manager::~Manager() {
  // Do nothing
}