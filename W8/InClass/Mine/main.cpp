#include <iostream>
using std::cout;

#include "Point2D.h"
#include "Point3D.h"

int main()
{
    Point p(1, 2);
    cout << p.toString() << "\n";

    Point3D start(3, 4, 5);
    cout << start.toString() << "\n";

    return 0;
}