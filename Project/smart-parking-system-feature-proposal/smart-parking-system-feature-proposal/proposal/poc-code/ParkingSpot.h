#ifndef PARKING_SPOT_H
#define PARKING_SPOT_H

#include "Vehicle.h"
#include <unordered_map>

class ParkingSpot {
public:
    ParkingSpot(int id, const std::unordered_map<int, double>& distancesToGate);

public:
    bool park(Vehicle* vehicle);
    Vehicle* leave();
    double getDistanceToGate(int gateID) const;
    int spotID();
    bool isOccupied();
    Vehicle* parkedVehicle();
private:
    int _spotID;
    bool _isOccupied;
    Vehicle* _parkedVehicle;
    std::unordered_map<int, double> _distancesToGate;
};

#endif