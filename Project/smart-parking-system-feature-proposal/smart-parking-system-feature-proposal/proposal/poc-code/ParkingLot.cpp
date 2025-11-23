#include <cfloat> // for DBL_MAX
#include <iostream>
#include <format>
#include "ParkingLot.h"

ParkingLot::ParkingLot(const std::string& name, const std::vector<Gate*>& gl, const std::vector<ParkingSpot*>& psl)
: _name(name), _gateList(gl), _parkingSpotList(psl), _maximumSpot(psl.size()), _occupiedSpot(0), _gateCount(gl.size()) {}

ParkingLot::~ParkingLot() {
    for (ParkingSpot* spot: _parkingSpotList) {
        delete spot;
    }

    for (Gate* gate: _gateList) {
        delete gate;
    }
}

void ParkingLot::printInfo() {
    std::cout << "THONG TIN BAI DO XE\n";
    std::cout << "Ten bai do xe: " << _name << '\n';
    std::cout << "So luong cong: " << _gateCount << '\n';
    std::cout << "So luong spot: " << _maximumSpot << '\n';

}

ParkingSpot* ParkingLot::findNearestAvailableSpot(Gate* g) {
    double bestDistance = DBL_MAX;
    ParkingSpot* bestSpot = nullptr;

    for (ParkingSpot* spot: _parkingSpotList) {
        if (spot->isOccupied()) continue;
        double dis = spot->getDistanceToGate(g->gateID());
        if (dis < bestDistance) {
            bestDistance = dis;
            bestSpot = spot;
        }
    }

    return bestSpot;
}

bool ParkingLot::checkIn(Vehicle* v, Gate* g) {
    std::cout << std::format("Phuong tien voi bang so xe {} dang tien vao cong {}\n",
        v->lincensePlate(), g->gateID());

    if (_occupiedSpot == _maximumSpot) {
        std::cout << "Bai giu xe da day\n";
        return false;
    }

    ParkingSpot *bestSpot = findNearestAvailableSpot(g);

    if (bestSpot) {
        bestSpot->park(v);
        _occupiedSpot++;
        std::cout << std::format("Da huong dan phuong tien voi bang so xe {} vao spot trong gan cong nhat co ID {}\n"
        , v->lincensePlate(), bestSpot->spotID());
        return true;
    } else {
        std::cout << "Khong tim thay bai do xe\n";
        return false;
    }
}

void ParkingLot::checkOut(Vehicle* v) {
    ParkingSpot* parkedSpot = nullptr;
    for (ParkingSpot* spot: _parkingSpotList) {
        if (spot->parkedVehicle() == v) {
            parkedSpot = spot;
            break;
        }
    }

    std::cout << std::format(
        "Phuong tien voi bien so xe {} da roi bai do xe\n",
        v->lincensePlate()
    );
    
    parkedSpot->leave();

    _occupiedSpot--;
}