#include <cmath>   // Dùng cho M_PI hoặc pow
#include <iomanip> // Dùng cho setprecision nếu cần
#include <iostream>
#include <sstream> // Dùng để định dạng chuỗi
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::vector;

// --- 1. Helper Utils ---
namespace Utils {
class String {
public:
  static vector<string> split(string haystack, string needle) {
    vector<string> result;
    int startPos = 0;
    size_t foundPos = haystack.find(needle, startPos);

    while (foundPos != string::npos) {
      int count = foundPos - startPos;
      string token = haystack.substr(startPos, count);
      result.push_back(token);

      startPos = foundPos + needle.length();
      foundPos = haystack.find(needle, startPos);
    }

    // The remaining
    string token = haystack.substr(startPos, haystack.length() - startPos);
    result.push_back(token);

    return result;
  }
};
} // namespace Utils

// --- 2. Base Classes (Theo UML) ---

// Lớp Object gốc (để tuân thủ UML)
class Object {
public:
  virtual string toString() = 0;
  virtual ~Object() {}
};

// Lớp IShape kế thừa Object
class IShape : public Object {
public:
  virtual double area() = 0;
  virtual double perimeter() = 0;
};

// Lớp Interface cho các Parser
class IParsable {
public:
  // Parse trả về Object* (để khớp với UML và dynamic_cast trong main)
  virtual Object *parse(string data) = 0;

  // Hàm này giúp Factory nhận diện Parser nào xử lý loại chuỗi nào (ví dụ
  // "Square")
  virtual string parsedObjectName() = 0;
  virtual ~IParsable() {}
};

// --- 3. Concrete Shapes ---

class Square : public IShape {
private:
  double _a;

public:
  Square(double a) : _a(a) {}
  double area() override { return _a * _a; }
  double perimeter() override { return _a * 4; }
  string toString() override {
    // Xóa các số 0 thừa nếu cần, hoặc dùng to_string đơn giản
    string s = to_string(_a);
    s.erase(s.find_last_not_of('0') + 1, string::npos);
    if (s.back() == '.')
      s.pop_back();
    return "Square: a=" + s;
  }
};

class Circle : public IShape {
private:
  double _radius;

public:
  Circle(double r) : _radius(r) {}
  double area() override { return 3.14 * _radius * _radius; }
  double perimeter() override { return 2 * 3.14 * _radius; }
  string toString() override {
    string s = to_string(_radius);
    s.erase(s.find_last_not_of('0') + 1, string::npos);
    if (s.back() == '.')
      s.pop_back();
    return "Circle: r=" + s;
  }
};

class Rectangle : public IShape {
private:
  double _width;
  double _height;

public:
  Rectangle(double w, double h) : _width(w), _height(h) {}
  double area() override { return _width * _height; }
  double perimeter() override { return (_width + _height) * 2; }
  string toString() override {
    string w = to_string(_width);
    w.erase(w.find_last_not_of('0') + 1, string::npos);
    if (w.back() == '.')
      w.pop_back();

    string h = to_string(_height);
    h.erase(h.find_last_not_of('0') + 1, string::npos);
    if (h.back() == '.')
      h.pop_back();

    return "Rectangle: w=" + w + ", h=" + h;
  }
};

// --- 4. Concrete Parsers ---

class SquareParser : public IParsable {
public:
  Object *parse(string data) override {
    // data format: "a=12"
    vector<string> tokens = Utils::String::split(data, "=");
    // tokens[1] là "12"
    double a = std::stod(tokens[1]);
    return new Square(a);
  }
  string parsedObjectName() override { return "Square"; }
};

class CircleParser : public IParsable {
public:
  Object *parse(string data) override {
    // data format: "r=12"
    vector<string> tokens = Utils::String::split(data, "=");
    double r = std::stod(tokens[1]);
    return new Circle(r);
  }
  string parsedObjectName() override { return "Circle"; }
};

class RectangleParser : public IParsable {
public:
  Object *parse(string data) override {
    // data format: "w=3, h=4"
    // Bước 1: Tách dấu phẩy -> ["w=3", "h=4"]
    vector<string> params = Utils::String::split(data, ", ");

    // Bước 2: Tách dấu bằng cho từng phần
    double w = 0, h = 0;
    for (auto &param : params) {
      vector<string> kv = Utils::String::split(param, "=");
      if (kv[0] == "w")
        w = std::stod(kv[1]);
      if (kv[0] == "h")
        h = std::stod(kv[1]);
    }
    return new Rectangle(w, h);
  }
  string parsedObjectName() override { return "Rectangle"; }
};

// --- 5. Factory ---

class ParserFactory {
private:
  vector<IParsable *> _parsers;

public:
  // Đăng ký các parser vào factory
  void registerWith(IParsable *parser) { _parsers.push_back(parser); }

  // Tìm parser phù hợp với type (ví dụ "Square")
  IParsable *create(string type) {
    for (auto parser : _parsers) {
      if (parser->parsedObjectName() == type) {
        return parser;
      }
    }
    return nullptr;
  }

  // Constructor tự động đăng ký các parser mặc định (để main chạy được ngay)
  ParserFactory() {
    registerWith(new SquareParser());
    registerWith(new CircleParser());
    registerWith(new RectangleParser());
  }

  // Destructor dọn dẹp bộ nhớ
  ~ParserFactory() {
    for (auto parser : _parsers) {
      delete parser;
    }
    _parsers.clear();
  }
};
int main() {
  // Dữ liệu mẫu
  vector<string> lines = {"Square: a=12",        "Circle: r=12",
                          "Square: a=7",         "Rectangle: w=3, h=4",
                          "Rectangle: w=6, h=8", "Circle: r=5",
                          "Square: a=8"};

  ParserFactory factory;
  vector<IShape *> shapes;

  for (auto &line : lines) {
    // Ví dụ: line = "Square: a=12"
    vector<string> tokens = Utils::String::split(line, ": ");
    // tokens[0] = "Square", tokens[1] = "a=12"

    IParsable *parser = factory.create(tokens[0]);

    if (parser != nullptr) {
      // Parse chuỗi thuộc tính thành Object, sau đó ép kiểu về IShape
      // Lưu ý: Sửa lỗi cú pháp dynamic_cast trong đề bài
      IShape *shape = dynamic_cast<IShape *>(parser->parse(tokens[1]));
      shapes.push_back(shape);
    }
  }

  // Xuất kết quả
  for (auto &shape : shapes) {
    if (shape != nullptr) {
      cout << shape->toString() << ": area=" << shape->area()
           << ", perimeter=" << shape->perimeter() << endl;
    }
  }

  // Dọn dẹp bộ nhớ các Shape đã tạo
  for (auto shape : shapes) {
    delete shape;
  }

  return 0;
}