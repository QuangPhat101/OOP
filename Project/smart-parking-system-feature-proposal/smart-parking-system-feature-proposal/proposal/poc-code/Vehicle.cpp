#include "Vehicle.h"

Vehicle::Vehicle(const std::string& plate) : _licensePlate(plate) {}

std::string Vehicle::lincensePlate() {
    return _licensePlate;
}