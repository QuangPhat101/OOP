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
  return format("{0:<20} | {1:<20} | {2:<50} | ${3:<20}", "Ý tưởng",
                this->_projectName,
                "Phát triển: " + to_string(this->_developMonths) + " tháng",
                to_string((long)this->calculateSponsor()));
}