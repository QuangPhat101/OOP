#ifndef _INTEGER_H_
#define _INTEGER_H_
#include "Object.h"
#include <string>

using std::string;

class Integer : public Object {
private:
  int _value;

public:
  Integer();
  Integer(int);
  int value();
  string toString();
};
#endif