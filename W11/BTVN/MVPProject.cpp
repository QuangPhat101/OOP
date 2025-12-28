#include "MVPProject.h"
MVPProject::MVPProject() {
  {
    // Do nothing
  }
}
MVPProject::MVPProject(string name, int runMonths, int mktMonths,
                       double runCostPerMonth, double mktCostPerMonth)
    : Project(name), _runMonths(runMonths), _mktMonths(mktMonths),
      _runCostPerMonth(runCostPerMonth), _mktCostPerMonth(mktCostPerMonth) {};

double MVPProject::calculateSponsor() const {
  return (this->_runMonths * this->_runCostPerMonth) +
         (this->_mktMonths * this->_mktCostPerMonth);
}
string MVPProject::toString() const {
  return format("Sản phẩm     | {}    | Vận hành : {} tháng.Marketing : {} "
                "tháng  | ${}       ",
                this->_projectName, this->_runMonths, this->_mktMonths,
                this->calculateSponsor());
}