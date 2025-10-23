#include "Point.h"

#include <iostream>
#include <format>
#include <regex>
using std::format;
using std::cin, std::cout;
using std::regex_match, std::regex, std::smatch;

string ui::toString(const Point& point) {
    return format("({}, {})",
        point.getX(), point.getY()
    );
}

Point ui::fromString(const string& str) {
    string pattern = R"((\d+\.?\d*), (\d+\.?\d*))";
    smatch match;

    if (str.empty()) {
        // TODO: Xử lý chuỗi rỗng
    } else if (!regex_match(str, match, regex(pattern))) {
        // TODO: Xử lý sai định dạng
    } else {
        float x = std::stof(match[1]);
        float y = std::stof(match[2]);
                
        return Point(x, y);
    }
    
    return Point(0, 0);
}

Point ui::requestPoint(string message) {
    cout << message;
    string buffer;
    getline(cin, buffer);

    Point result = fromString(buffer);
    return result;
}