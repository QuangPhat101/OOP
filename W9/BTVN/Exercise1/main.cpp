#include <iostream>
#include <string>
#include <vector>
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Utils.h"
#include "ParserFactory.h"
#include "IParsable.h"
using std::cout, std::cin;
using std::vector;
using std::string;
using std::endl;


int main() {
    ParserFactory factory; // We inject what we want to work with here
    factory.registerWith(new RectangleParser());
    factory.registerWith(new SquareParser());
    factory.registerWith(new CirleParser());
    vector<string> lines = {
        "Square: a=12",
        "Circle: r=12",
        "Square: a=7",
        "Rectangle: w=3, h=4",
        "Rectangle: w=6, h=8",
        "Circle: r=5",
        "Square: a=8"
    };
    vector<IShape*> shapes;

    for (auto& line : lines) {
				// Example: line = "Square: a=12"
				vector<string> tokens = Utils::String::split(line, ": ");
				IParsable* parser = factory.create(tokens[0]); // "Square"=> SquareParser
        IShape* shape = dynamic_cast<IShape*> (parser->parse(tokens[1])); // "a=12" => Square(_a = 12)
        shapes.push_back(shape);
    }

    for (auto& shape : shapes) { // Polymorphism
        auto converter = containers[typeid(*shape).name()];
        string info = converter->convert(shape);
        cout << info << "\n";
    }
}
