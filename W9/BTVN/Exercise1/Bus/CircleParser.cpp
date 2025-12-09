#include "CircleParser.h"

Object *CircleParser::parse(string data) {
  // 1. Tạo đối tượng Circle mới
  Circle *circle = new Circle();

  // 2. Tách chuỗi (đề phòng trường hợp có nhiều thuộc tính, hoặc để lọc rác)
  // data có thể là: " r=12" (có khoảng trắng thừa do cắt chuỗi ở main)
  vector<string> tokens = Utils::String::split(data, ",");

  for (string &token : tokens) {
    // Tìm dấu "="
    int splitPos = token.find("=");
    if (splitPos == string::npos)
      continue;

    // Tách key và value
    string key = token.substr(0, splitPos);
    string valueStr = token.substr(splitPos + 1);

    // 3. Kiểm tra key và gán dữ liệu
    // Dùng .find("r") để tìm chữ r, bỏ qua các khoảng trắng thừa nếu có
    if (key.find("r") != string::npos) {
      // Giả sử class Circle có hàm setRadius
      float r = stof(valueStr);
      circle->setRadius(r);
    }
  }

  // 4. Trả về đối tượng đã có dữ liệu
  return circle;
}

CircleParser::CircleParser() {
  // Do nothing
}
string CircleParser::toString() { return "Circle"; }