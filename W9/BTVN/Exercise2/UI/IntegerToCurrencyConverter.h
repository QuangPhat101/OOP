#ifndef _INTEGERTOCURRENCYCONVERTER_H_
#define _INTEGERTOCURRENCYCONVERTER_H_

#include "../DTO/Integer.h"
#include "../DTO/Object.h"
#include "IValueConverter.h"
#include <string>
using std::string;

class IntegerToCurrencyConverter : public IConverter {
public:
  IntegerToCurrencyConverter();

public:
  string convert(Object *object) override;
};

#endif