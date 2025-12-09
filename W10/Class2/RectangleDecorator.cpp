#include "RectangleDecorator.h"

RectangleDecorator::RectangleDecorator() : Decorator() {
  // Do nothing
}
RectangleDecorator::RectangleDecorator(IShape *shape, bool isFilled,
                                       char symbol)
    : Decorator(shape, isFilled, symbol) {
  // Do nothing
}
RectangleDecorator::~RectangleDecorator() {
  // Do nothing
}
void RectangleDecorator::draw() {
  auto rect = dynamic_cast<Rectangle *>(_shape); // downcast
  for (int i = 0; i < rect->height(); i++) {
    for (int j = 0; j < rect->width(); j++) {
      if (_isFilled) {
        std::cout << _symbol;
      } else {
        if (i == 0 || i == rect->height() - 1 || j == 0 ||
            j == rect->width() - 1) {
          std::cout << _symbol;
        } else {
          std::cout << ' ';
        }
      }
    }
    std::cout << std::endl;
  }
}