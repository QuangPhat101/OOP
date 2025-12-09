#ifndef _IPARSABLE_H_
#define _IPARSABLE_H_
#include "../DTO/Circle.h"
#include "../DTO/Object.h"
#include "../DTO/Rectangle.h"
#include "../DTO/Square.h"
#include <string>
using std::string;

class IParsable : public Object {
public:
  virtual Object *parse(string data) = 0;

public:
  string toString() override;
};

#endif