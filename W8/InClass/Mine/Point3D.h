#ifndef _POINT3D_H_
#define _POINT3D_H_
#include <string>
#include "Point2D.h"
#include <format>
using std::format;
using std::string;

class Point3D : public Point
{
private:
    float _z;

public:
    Point3D();
    Point3D(float, float, float);
    ~Point3D();
    string toString();
};

#endif