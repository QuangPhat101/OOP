#ifndef _PARSERFACTORY_H_
#define _PARSERFACTORY_H_
#include "../DTO/Object.h"
#include "IParsable.h"
#include <iostream>
#include <map>
#include <string>
using std::map;
using std::string;

class ParserFactory : public Object {
private:
  map<string, IParsable *>
      _container; // A container for all the dependencies injection
public:
  void registerWith(IParsable *parser);
  IParsable *create(string type);
  string toString() override;
};

#endif