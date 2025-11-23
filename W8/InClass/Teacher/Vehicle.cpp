#include "vehicle.h"
#include <iostream>
using std::cout;
Vehicle::Vehicle()
{
    cout << "Hàm tạo kh đối của vehicle\n";
}
Vehicle::Vehicle(string brandName){
    cout <<"hàm tạo có đối của vehicle\n";
}
Vehicle::~Vehicle()
{
    cout << "Hàm hủy của vehicle\n";
}