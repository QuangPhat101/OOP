#ifndef _DAILYEMPLOYEEPARSER_H_
#define _DAILYEMPLOYEEPARSER_H_
#include "../DTO/DailyEmployee.h"
#include "../Helper/Utils.h"
#include "IParsable.h"

class DailyEmployeeParser : public IParsable {
public:
  DailyEmployee *parse(string data) override;

public:
  DailyEmployeeParser();
  string toString() override;
};

#endif