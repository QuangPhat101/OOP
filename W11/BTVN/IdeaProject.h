#pragma once
#include "Project.h"
#include <format>
using namespace std;

class IdeaProject : public Project {
public:
  int _developMonths;
  double _devCost;

public:
  IdeaProject();
  IdeaProject(string name, int developMonths, double devCost);
  double calculateSponsor() const override;
  string toString() const override;
};