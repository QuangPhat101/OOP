#ifndef _IVALUECONVERTER_H_
#define _IVALUECONVERTER_H_

#include "../DTO/Object.h"
#include <string>
using std::string;

class IConverter : public Object {
public:
  virtual string convert(Object *object) = 0;

public:
  string toString() override;
};
#endif
