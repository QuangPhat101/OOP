#ifndef _RECTANGLEPARSER_H
#define _RECTANGLEPARSER_H

#include "../Helper/Utils.h"
#include "IParsable.h"
#include <string>
#include <vector>
using std::string;

class RectangleParser : public IParsable {
public:
  Object *parse(string data) override;

public:
  RectangleParser();
  string toString() override;
};

#endif