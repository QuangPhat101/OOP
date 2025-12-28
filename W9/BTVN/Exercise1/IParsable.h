#ifndef _IPARSABLE_H_
#define _IPARSABLE_H_
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"

class IParsable{
public: 
    virtual string parse(string) = 0;

};

class RectangleParser : public IParsable{
public: 

};
class SquareParser : public IParsable{
public: 

};
class CircleParser : public IParsable{
public: 

};
#endif