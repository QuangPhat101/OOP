#include "integer.h"

Integer::Integer() { _value = 0; }

Integer::Integer(int value) { _value = value; }

string Integer::toString() { return "Integer"; }

int Integer::value() { return _value; }