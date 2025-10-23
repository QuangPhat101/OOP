#include "Point.h"
#include <iostream>
#include <format>
using std::cout;
using std::format;

float Point::getX() const
{
    return this->_x;
}

float Point::getY() const
{
    return _y;
}

void Point::setX(float value)
{
    _x = value;
}

void Point::setY(float value)
{
    _y = value;
}

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

Point::Point(float value)
{
    _x = _y = value;
}

Point::~Point()
{
    // cout << "Point destructor\n";
}
