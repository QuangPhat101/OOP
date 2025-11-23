#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include <iostream>
using std::string;
class Vehicle
{
protected:
    string _brandName;
public: 
    Vehicle();
    Vehicle(string brandName);
    ~Vehicle();

};

#endif