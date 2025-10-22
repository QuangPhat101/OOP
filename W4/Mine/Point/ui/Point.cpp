#include "Point.h"

#include <format>
using std::format;

std::string ui::toString()(const Point& p){
    return format("({}, {})", p.getX(), p.getY());
}