#ifndef _MANAGERPARSER_H_
#define _MANAGERPARSER_H_

#include "../DTO/Manager.h"
#include "../Helper/Utils.h"
#include "IParsable.h"

class ManagerParser : public IParsable {
public:
  Manager *parse(string data) override;

public:
  ManagerParser();
  string toString() override;
};

#endif