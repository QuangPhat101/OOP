#include "NumberFormatInfo.h"

string NumberFormatInfo::currencyDecimalSeparator() {
  return _currencyDecimalSeparator;
}
string NumberFormatInfo::currencySymbol() { return _currencySymbol; }
int NumberFormatInfo::currencyPositive() { return _currencyPositive; }
string NumberFormatInfo::currencyPositiveFormat() {
  return _currencyPositiveFormat;
}
string NumberFormatInfo::toString() {
  return "Currency Symbol: " + _currencySymbol +
         ", Currency Decimal Separator: " + _currencyDecimalSeparator +
         ", Currency Positive: " + std::to_string(_currencyPositive) +
         ", Currency Positive Format: " + _currencyPositiveFormat;
}