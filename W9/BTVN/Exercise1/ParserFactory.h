#ifndef _PARSERFACTORY_H_
#define _PARSERFACTORY_H_
#include <iostream>
#include <map>
#include <string>
#include "IParsable.h"
using std::map;
using std::string;


class ParserFactory {
private:
	map<string, IParsable*> _container; // A container for all the dependencies injection
public:
	void registerWith(IParsable* parser);
	IParsable* create (string type);
};

#endif