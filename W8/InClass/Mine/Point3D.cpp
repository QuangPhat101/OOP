#include "Point3D.h"

Point3D::Point3D()
{
    // Do nothing
}
Point3D::Point3D(float x, float y, float z)
    : Point(x, y), _z(z)
{
    //this->_z = z;
}
Point3D::~Point3D()
{
    // Do nothing
}
string Point3D::toString() 
{
    string base = Point::toString();
    base.pop_back();
    string result = std::format(
        "{}, {})", base, _z);
    return result;
}
