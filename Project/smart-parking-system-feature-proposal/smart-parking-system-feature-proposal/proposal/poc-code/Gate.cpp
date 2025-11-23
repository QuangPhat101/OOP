#include "Gate.h"

Gate::Gate(int id) : _gateID(id) {}

int Gate::gateID() {
    return _gateID;
}