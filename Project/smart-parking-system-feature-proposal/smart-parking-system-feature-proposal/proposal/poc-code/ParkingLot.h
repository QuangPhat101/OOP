#ifndef PARKING_LOT_H
#define PARKING_LOT_H

#include <vector>
#include "Gate.h"
#include "ParkingSpot.h"

class ParkingLot {
public:
    ParkingLot(const std::string& name, const std::vector<Gate*>& gateList, const std::vector<ParkingSpot*>& parkingSpotList);
    ~ParkingLot();
    void printInfo();
    bool checkIn(Vehicle*, Gate*);
    void checkOut(Vehicle*);
    ParkingSpot* findNearestAvailableSpot(Gate*);

private:
    std::string _name;
    int _gateCount;
    int _maximumSpot;
    int _occupiedSpot;
    std::vector<Gate*> _gateList;
    std::vector<ParkingSpot*> _parkingSpotList;
};


#endif