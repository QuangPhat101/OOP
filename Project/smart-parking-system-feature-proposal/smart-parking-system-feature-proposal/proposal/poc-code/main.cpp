#include "ParkingLot.h"
#include <iostream>

using std::cout;


// DATA /////////////////////////////////////////////////////////////////////////////////////////
// Duoi day la du lieu cua object parkingLot. Vi muon giu tinh don gian cua code PoC, nhom se
// hardcode du lieu bai do xe vao file main.cpp. Cac giai doan sau nhom se phat trien tinh nang
// nhap du lieu bai do xe bang tay (tren console cua chuong trinh) hoac bang file
// Bai xe co 2 cong, 4 slot. Spot 1 va spot 2 gan cong 1 hon, Spot 3 va Spot 4 gan cong 2 hon
void loadData(std::vector<Gate*>& gateList, std::vector<ParkingSpot*>& parkingSpotList) {
    // Gates:
    gateList[0] = new Gate(1);
    gateList[1] = new Gate(2);

    // Spot 1:
    std::unordered_map<int, double> distancesFromSpot1 = {{1, 2.0}, {2, 5.0}};
    parkingSpotList[0] = new ParkingSpot(1, distancesFromSpot1);
    
    // Spot 2:
    std::unordered_map<int, double> distancesFromSpot2 = {{1, 3.0}, {2, 6.0}};
    parkingSpotList[1] = new ParkingSpot(2, distancesFromSpot2);
    
    // Spot 3:
    std::unordered_map<int, double> distancesFromSpot3 = {{1, 5.0}, {2, 2.0}};
    parkingSpotList[2] = new ParkingSpot(3, distancesFromSpot3);
    
    // Spot 4:
    std::unordered_map<int, double> distancesFromSpot4 = {{1, 6.0}, {2, 3.0}};
    parkingSpotList[3] = new ParkingSpot(4, distancesFromSpot4);
}

int main() {
    cout << "CHUONG TRINH DEMO POC DO AN OOP - NHOM 16.\n";
    cout << "Chuong trinh mo phong chuc nang check in - check out bai giu xe.\n\n";
    
    std::vector<Gate*> gateList(2);
    std::vector<ParkingSpot*> parkingSpotList(4);
    
    loadData(gateList, parkingSpotList);
    ParkingLot parkingLot = ParkingLot("HCMUS - Parking Lot", gateList, parkingSpotList);
    
    parkingLot.printInfo();
    cout << '\n';

    // Xe 1 vao bai bang cong 1
    Vehicle* vehicle1 = new Vehicle("001");
    parkingLot.checkIn(vehicle1, gateList[0]);
    cout << '\n';
    
    // Xe 2 vao bai bang cong 2
    Vehicle* vehicle2 = new Vehicle("002");
    parkingLot.checkIn(vehicle2, gateList[1]);
    cout << '\n';

    // Xe 3 vao bai bang cong 1
    Vehicle* vehicle3 = new Vehicle("003");
    parkingLot.checkIn(vehicle3, gateList[0]);
    cout << '\n';

    // Xe 4 vao bai bang cong 1
    Vehicle* vehicle4 = new Vehicle("004");
    parkingLot.checkIn(vehicle4, gateList[0]);
    cout << '\n';
    
    // Xe 5 vao bai bang cong 2 -> khong vao duoc do bai xe da day
    Vehicle* vehicle5 = new Vehicle("005");
    parkingLot.checkIn(vehicle5, gateList[1]);
    cout << '\n';
    
    // Xe 1 check out
    parkingLot.checkOut(vehicle1);
    cout << '\n';
    
    // Xe 5 vao bai bang cong 2 -> bay gio thi vao duoc
    parkingLot.checkIn(vehicle5, gateList[1]);
    cout << '\n';

    // Giai phong bo nho tren heap cua cac object Vehicle
    delete vehicle1;
    delete vehicle2;
    delete vehicle3;
    delete vehicle4;
    delete vehicle5;

    // Cac Gate va ParkingSpot duoc giai phong trong destructor cua ParkingLot

    return 0;
}

