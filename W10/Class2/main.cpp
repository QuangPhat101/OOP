#include "IShape.h"
#include "Rectangle.h"
#include "RectangleDecorator.h"
#include "Square.h"
#include "SquareDecorator.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  std::vector<IShape *> shapes = {new Rectangle(10, 6), new Square(5),
                                  new Rectangle(8, 5), new Square(3)};

  std::vector<Decorator *> decoratedShapes;
  decoratedShapes.push_back(new RectangleDecorator(shapes[0], true, '*'));
  decoratedShapes.push_back(new SquareDecorator(shapes[1], false, '+'));
  decoratedShapes.push_back(new RectangleDecorator(shapes[2], true, '@'));
  decoratedShapes.push_back(new SquareDecorator(shapes[3], false, '-'));

  for (auto decorator : decoratedShapes) {
    cout << decorator->getShape()->toString() << ":\n";
    decorator->draw();
    std::cout << std::endl;
  }

  return 0;
}
