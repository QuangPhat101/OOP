#ifndef NUMBERFORMATINFO_H
#define NUMBERFORMATINFO_H
#include "Object.h"
#include <string>
using std::string;

class NumberFormatInfo : public Object {
private:
  string _currencyDecimalSeparator = ".";
  string _currencySymbol = "d";
  int _currencyPositive = 3;
  string _currencyPositiveFormat = "n $";

public:
  string currencyDecimalSeparator();
  string currencySymbol();
  int currencyPositive();
  string currencyPositiveFormat();

public:
  string toString() override;
};
#endif