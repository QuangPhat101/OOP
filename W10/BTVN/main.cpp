#include "FillEnum.h"
#include "IShape.h"
#include "Rectangle.h"
#include "RectangleDecorator.h"
#include "ShapeDecorator.h"
#include "Square.h"
#include "SquareDecorator.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  std::vector<IShape *> shapes = {
      new Rectangle(10, 6),
      new Square(5),
      new Rectangle(8, 5),
      new Square(3),
  };
  for (auto shape : shapes) {
    cout << shape->toString() << endl;
  }
  std::vector<ShapeDecorator *> shapesDecorator = {
      new RectangleDecorator(shapes[0], FillEnum::Solid, '*'),
      new SquareDecorator(shapes[1], FillEnum::Solid, '+'),
      new RectangleDecorator(shapes[2], FillEnum::Hollow, '@'),
      new SquareDecorator(shapes[3], FillEnum::Hollow, '-'),
  };
  for (auto shapeDecorator : shapesDecorator) {
    shapeDecorator->draw();
  }
  for (auto *shapeDecorator : shapesDecorator) {
    delete shapeDecorator;
  }
  for (IShape *shape : shapes)
    delete shape;
  return 0;
}
