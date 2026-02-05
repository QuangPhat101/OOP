#pragma once
#include <format>
#include <iostream>
#include <string>

using namespace std;

class Project {
protected:
  string _projectName;

public:
  Project() {};
  Project(string name) { this->_projectName = name; };
  virtual string toString() const = 0;
  virtual ~Project() = default;
  virtual double calculateSponsor() const = 0;
};