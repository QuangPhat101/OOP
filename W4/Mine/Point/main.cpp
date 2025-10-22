#include <iostream>

#include "dto/Point.h"
#include "ui/Point.h"
#include "bus/Point.h"
using std::cout;

int main()
{
    // Point *p = new Point();
    // cout << p->toString();
    // delete p;

    Point p1(4, 7);
    cout << ui::toString(p1) << std::endl;

    Point p2(5);
    cout << ui::toString(p2) << std::endl;

    float distance = bus::calcDistance(p1, p2);
    return 0;
}
