#include "ParserFactory.h"
#include "IParsable.h"

void ParserFactory::registerWith(IParsable* parser) { 
		_container.insert(
			{typeid(*parser).name(), parser}
		);
}
