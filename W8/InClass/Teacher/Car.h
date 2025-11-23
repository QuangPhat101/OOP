#ifndef _CAR_H_
#define _CAR_H_
#include "vehicle.h"

class Car : public Vehicle
{
public:
    Car(string name);
    ~Car();
};

#endif