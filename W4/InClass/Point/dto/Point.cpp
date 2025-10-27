#include "Point.h"
#include <iostream>
using namespace std;

float Point::getX() const
{
    return _x;
}
float Point::getY() const
{
    return _y;
}

void Point::setX(float x)
{
    _x = x;
}
void Point::setY(float y)
{
    _y = y;
}

// Hàm tạo
Point::Point()
{
    _x = 0;
    _y = 0;
}

Point::Point(float x, float y)
{
    this->_x = x;
    this->_y = y;
}
Point::Point(float x)
{
    _x = _y = x;
}
// Hàm hủy

Point::~Point()
{
    cout << "Point destructor\n";
}

// Hàm xuất
string Point::toString()
{
    return format("({}, {})", this->_x, this->_y);
}