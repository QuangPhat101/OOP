#ifndef _CIRCLEPARSER_H
#define _CIRCLEPARSER_H
#include "../Helper/Utils.h"
#include "IParsable.h"
#include <string>
#include <vector>
using std::string;

class CircleParser : public IParsable {
public:
  Object *parse(string data) override;

public:
  CircleParser();
  string toString() override;
};

#endif