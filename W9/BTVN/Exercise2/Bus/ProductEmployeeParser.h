#ifndef _PRODUCTEMPLOYEEPARSER_H_
#define _PRODUCTEMPLOYEEPARSER_H_

#include "../DTO/Object.h"
#include "../DTO/ProductEmployee.h"
#include "../Helper/Utils.h"
#include "IParsable.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class ProductEmployeeParser : public IParsable {
public:
  ProductEmployee *parse(string data) override;

public:
  ProductEmployeeParser();
  string toString() override;
};
#endif
