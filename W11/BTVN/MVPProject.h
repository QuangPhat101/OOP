#pragma once
#include "Project.h"
#include <format>
using namespace std;

class MVPProject : public Project {
public:
  int _runMonths;
  int _mktMonths;
  double _runCostPerMonth;
  double _mktCostPerMonth;

public:
  MVPProject();
  MVPProject(string name, int runMonths, int mktMonths, double runCostPerMonth,
             double mktCostPerMonth);
  double calculateSponsor() const override;
  string toString() const override;
};