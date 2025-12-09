#include "ParserFactory.h"
#include "IParsable.h"

void ParserFactory::registerWith(IParsable *parser) {
  _container.insert({parser->toString(), parser});
}

IParsable *ParserFactory::create(string type) { return _container[type]; }
string ParserFactory::toString() { return "ParserFactory"; }