#ifndef _SQUAREPARSER_H
#define _SQUAREPARSER_H

#include "../Helper/Utils.h"
#include "IParsable.h"
#include <string>
#include <vector>
using std::string;

class SquareParser : public IParsable {
public:
  Object *parse(string data) override;

public:
  SquareParser();
  string toString() override;
};

#endif