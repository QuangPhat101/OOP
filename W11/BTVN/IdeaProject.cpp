#include "IdeaProject.h"

IdeaProject::IdeaProject() {
  // Do nothing
}
IdeaProject::IdeaProject(string name, int developMonths, double devCost)
    : Project(name), _developMonths(developMonths), _devCost(devCost) {};
double IdeaProject::calculateSponsor() const {
  return _developMonths * _devCost;
}
string IdeaProject::toString() const {
  return format(
      "Ý tưởng    | {}    | Phát triển : {} tháng         | ${}       ",
      this->_projectName, this->_developMonths, this->calculateSponsor());
}