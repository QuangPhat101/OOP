#include <format>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#include "Circle.h"
#include "IShape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"

class IConverter { // IValueConverter (C#)
public:
  virtual string convert(IShape *shape) = 0;
};

class Rectangle2StringConverter : public IConverter {
public:
  string convert(IShape *shape) override;
};

class Square2StringConverter : public IConverter {
public:
  string convert(IShape *shape) override;
};
class Cirle2StringConverter : public IConverter {
public:
  string convert(IShape *shape) override;
};
class Triangle2StringConverter : public IConverter {
public:
  string convert(IShape *shape) override;
};

string Rectangle2StringConverter::convert(IShape *shape) {
  Rectangle *rect = dynamic_cast<Rectangle *>(shape); // downcast
  // TODO: không cast được thì return gì?
  return format("Chữ nhật: A={}, B={}, Chu vi={}, Diện tích={}", rect->width(),
                rect->height(), rect->perimeter(), rect->area());
}

string Square2StringConverter::convert(IShape *shape) {
  Square *square = dynamic_cast<Square *>(shape);
  return format("Vuông: Cạnh={}, Chu vi = {}, Diện tích={}", square->side(),
                square->perimeter(), square->area());
}

string Cirle2StringConverter::convert(IShape *shape) {
  Circle *circle = dynamic_cast<Circle *>(shape);
  return format("Hình tròn: Bán kính={}, Chu vi = {}, Diện tích={}",
                circle->radius(), circle->perimeter(), circle->area());
}
string Triangle2StringConverter::convert(IShape *shape) {
  Triangle *triangle = dynamic_cast<Triangle *>(shape);
  return format(
      "Tam giác: Cạnh a={}, Cạnh b={}, Cạnh c={}, Chu vi = {}, Diện tích={}",
      triangle->a(), triangle->b(), triangle->c(), triangle->perimeter(),
      triangle->area());
}
int main() {
  map<string, IConverter *> containers = {
      {typeid(Rectangle).name(), new Rectangle2StringConverter()},
      {typeid(Square).name(), new Square2StringConverter()},
      // TODO: chỗ duy nhất cần thêm
      {typeid(Circle).name(), new Cirle2StringConverter()},
      {typeid(Triangle).name(), new Triangle2StringConverter()}};

  vector<IShape *> shapes = {
      new Rectangle(3, 5),   new Circle(6),       new Square(5),
      new Triangle(3, 5, 6), new Rectangle(7, 1), new Rectangle(6, 2),
      new Square(9),         new Circle(12),      new Triangle(3, 4, 5),
  };

  for (auto shape : shapes) {
    auto converter = containers[typeid(*shape).name()];
    string info = converter->convert(shape);
    cout << info << "\n";
  }

  for (int i = 0; i < shapes.size(); ++i) {
    delete shapes[i];
  }
  shapes.clear();
  return 0;
}