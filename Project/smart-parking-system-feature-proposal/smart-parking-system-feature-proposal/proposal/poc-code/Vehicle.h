#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
public:
    Vehicle(const std::string& plate);
    std::string lincensePlate();
private:
    std::string _licensePlate;
};

#endif