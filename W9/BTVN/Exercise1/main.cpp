#include "Bus/CircleParser.h"
#include "Bus/IParsable.h"
#include "Bus/ParserFactory.h"
#include "Bus/RectangleParser.h"
#include "Bus/SquareParser.h"
#include "DTO/Circle.h"
#include "DTO/IShape.h"
#include "DTO/Rectangle.h"
#include "DTO/Square.h"
#include "Helper/Utils.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout, std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {
  // Input
  vector<string> lines = {"Square: a=12",        "Circle: r=12",
                          "Square: a=7",         "Rectangle: w=3, h=4",
                          "Rectangle: w=6, h=8", "Circle: r=5",
                          "Square: a=8"};

  ParserFactory factory;
  factory.registerWith(new SquareParser());
  factory.registerWith(new CircleParser());
  factory.registerWith(new RectangleParser());

  vector<IShape *> shapes;

  for (auto &line : lines) {
    // Line: "Square: a=12"
    vector<string> tokens = Utils::String::split(line, ": ");
    IParsable *parser = factory.create(tokens[0]); // "Square"

    if (parser != nullptr) {
      IShape *shape = dynamic_cast<IShape *>(parser->parse(tokens[1]));
      shapes.push_back(shape);
    }
  }

  // Output: Không dùng Converter, gọi trực tiếp hàm của Shape
  for (auto &shape : shapes) {
    cout << shape->toString() << "\n";
  }

  // Dọn dẹp bộ nhớ
  for (auto s : shapes)
    delete s;
}