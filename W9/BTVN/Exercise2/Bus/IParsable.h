#ifndef _IPARSABLE_H_
#define _IPARSABLE_H_

#include "../DTO/Object.h"
#include <string>
using std::string;

class IParsable : public Object {
public:
  virtual Object *parse(string data) = 0;

public:
  string toString() override = 0;
};
#endif