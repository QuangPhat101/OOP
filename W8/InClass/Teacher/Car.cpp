#include "Car.h"
#include <iostream>
using std::cout;

//sẽ khiến hàm tạo vehicle có đối
Car::Car(string name) : Vehicle(name)
{
    cout << "Hàm tạo có đối của car\n";
}
//Làm hàm tạo vehicle không đối

// Car::Car(string name) 
// {
//     cout << "Hàm tạo có đối của car\n";
// }

Car::~Car()
{
    cout << "Hàm hủy của car\n";
}