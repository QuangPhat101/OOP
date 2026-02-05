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
  return format(
      "{0:<20} | {1:<20} | {2:<51} | ${3:<20}", "Sản Phẩm", this->_projectName,
      "Vận hành: " + to_string((long)this->_runMonths) +
          " tháng. Marketing: " + to_string((long)this->_mktMonths) + " tháng",
      to_string((long)this->calculateSponsor()));
}