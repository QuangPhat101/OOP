#include "Point.h"
#include <math.h>

float bus::calcDistance(const Point &p1, const Point &p2)
{
    float dx = p2.getX() - p1.getX();
    float dy = p2.getY() - p1.getY();
    return sqrt(dx * dx + dy * dy);
}