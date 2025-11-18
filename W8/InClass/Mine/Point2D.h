#ifndef _POINT2D_H_
#define _POINT2D_H_
#include <string>
using std::string;

class Point
{
protected:
    float _x;
    float _y;

public:
    Point();
    Point(float, float);

public:
    string toString();
};

#endif