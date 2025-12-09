#ifndef _PARSERFACTORY_H_
#define _PARSERFACTORY_H_
#include "../DTO/Object.h"
#include "IParsable.h"
#include <map>
using std::map;

class ParserFactory : public Object {
private:
  map<string, IParsable *> _container;

public:
  void registerWith(string typeName, IParsable *parser);
  IParsable *create(string type);
  string toString() override;
};

#endif
