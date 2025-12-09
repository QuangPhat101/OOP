#include "RectangleParser.h"

Object *RectangleParser::parse(string data) {
  // data có dạng: " w=3, h=4" (có thể có khoảng trắng thừa)

  // 1. Tạo đối tượng Rectangle
  Rectangle *rect = new Rectangle();

  // 2. Cắt chuỗi theo dấu phẩy để tách w và h
  vector<string> tokens = Utils::String::split(data, ",");

  // 3. Duyệt qua từng thuộc tính
  for (string &token : tokens) {
    // Tìm vị trí dấu "="
    int splitPos = token.find("=");
    if (splitPos == string::npos)
      continue;

    // Tách key và value
    string key = token.substr(0, splitPos);
    string valueStr = token.substr(splitPos + 1);

    // 4. Kiểm tra key để set chiều rộng (w) hoặc chiều cao (h)
    // Dùng .find() để bỏ qua lỗi khoảng trắng (ví dụ " w")
    if (key.find("w") != string::npos) {
      rect->setWidth(
          stof(valueStr)); // Dùng stof cho số thực (hoặc stoi cho số nguyên)
    } else if (key.find("h") != string::npos) {
      rect->setHeight(stof(valueStr));
    }
  }

  return rect;
}
RectangleParser::RectangleParser() {
  // Do nothing
}
string RectangleParser::toString() { return "Rectangle"; }