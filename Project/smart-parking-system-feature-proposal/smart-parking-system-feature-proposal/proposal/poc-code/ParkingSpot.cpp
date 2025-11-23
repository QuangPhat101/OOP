#include "ParkingSpot.h"
#include <cfloat> // for DBL_MAX

ParkingSpot::ParkingSpot(int spotID, const std::unordered_map<int, double>& distancesToGate) : 
    _spotID(spotID), 
    _isOccupied(false), 
    _parkedVehicle(nullptr),
    _distancesToGate(distancesToGate)
{}

bool ParkingSpot::park(Vehicle* vehicle) {
    if (_isOccupied) {
        return false;
    }
    _parkedVehicle = vehicle;
    _isOccupied = true;
    return true;
}

Vehicle* ParkingSpot::leave() {
    Vehicle* leavingVehicle = _parkedVehicle;
    _parkedVehicle = nullptr;
    _isOccupied = false;
    return leavingVehicle;
}

double ParkingSpot::getDistanceToGate(int gateID) const {
    auto it = _distancesToGate.find(gateID);
    
    if (it != _distancesToGate.end()) {
        return it->second; 
    }
    
    return DBL_MAX; // khong tim thay -> Xa vo cung
}
int ParkingSpot::spotID() {
    return _spotID;
}

bool ParkingSpot::isOccupied() {
    return _isOccupied;
}

Vehicle* ParkingSpot::parkedVehicle() {
    return _parkedVehicle;
}