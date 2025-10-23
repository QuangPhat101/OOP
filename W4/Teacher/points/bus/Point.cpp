#include "Point.h"
#include <math.h>

float bus::calcDistance(const Point& p1, const Point& p2) {
    float deltaX = p2.getX() - p1.getX();
    float deltaY = p2.getY() - p1.getY();
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}