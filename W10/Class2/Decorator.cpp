#include "Decorator.h"

Decorator::Decorator() {
  this->_shape = nullptr;
  this->_isFilled = false;
  this->_symbol = ' ';
}
Decorator::Decorator(IShape *shape, bool isFilled, char symbol) {
  this->_shape = shape;
  this->_isFilled = isFilled;
  this->_symbol = symbol;
}
Decorator::~Decorator() { delete this->_shape; }

IShape *Decorator::getShape() const { return this->_shape; }
bool Decorator::isFilled() const { return this->_isFilled; }
char Decorator::getSymbol() const { return this->_symbol; }
