#include "Point.h"
#include <iostream>
#include <math.h>
using std::cout, std::cin;

#include "Float.h"

expected<Point, string> Point::getPoint(string message) {
    cout << message << "\n";
    auto result = Float::getFloatRetry("-->Nhập x:");
    
    if (!result.has_value()) {
        return unexpected(result.error());
    }
    float x = result.value();
    
    
    result = Float::getFloatRetry("-->Nhập y: ");
    if (!result.has_value()) {
        return unexpected(result.error());
    }
    float y = result.value();
    
    Point p;
    p._x = x;
    p._y = y;
    return p;
}

void Point::output() const {
    cout << "(" << _x << ", " << _y << ")";
} 

float Point::distance(Point start, Point end) {
    float dx = start._x - end._x;
    float dy = start._y - end._y;
    float result = sqrt(dx * dx + dy * dy);
    
    return result;
}