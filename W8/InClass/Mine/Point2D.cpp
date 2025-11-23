#include "Point2D.h"
#include <format>
using std::format;

Point::Point()
{
    // Do nothing
}

Point::Point(float x, float y)
{
    this->_x = x;
    this->_y = y;
}

string Point::toString()
{
    string result = format(
        "({}, {})",
        _x, _y);

    return result;
}