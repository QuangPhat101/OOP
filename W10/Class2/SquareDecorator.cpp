#include "SquareDecorator.h"

SquareDecorator::SquareDecorator() : Decorator() {
  // Do nothing
}
SquareDecorator::SquareDecorator(IShape *shape, bool isFilled, char symbol)
    : Decorator(shape, isFilled, symbol) {
  // Do nothing
}
SquareDecorator::~SquareDecorator() {
  // Do nothing
}
void SquareDecorator::draw() {
  auto square = dynamic_cast<Square *>(_shape); // downcast
  for (int i = 0; i < square->side(); i++) {
    for (int j = 0; j < square->side(); j++) {
      if (_isFilled) {
        std::cout << _symbol;
      } else {
        if (i == 0 || i == square->side() - 1 || j == 0 ||
            j == square->side() - 1) {
          std::cout << _symbol;
        } else {
          std::cout << ' ';
        }
      }
    }
    std::cout << std::endl;
  }
}
