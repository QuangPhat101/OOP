#include "ParserFactory.h"

void ParserFactory::registerWith(string typeName, IParsable *parser) {
  _container.insert({typeName, parser});
}
IParsable *ParserFactory::create(string type) { return _container[type]; }

string ParserFactory::toString() { return "ParserFactory"; }