#include "SquareParser.h"

Object *SquareParser::parse(string data) {
  // data có dạng: " a=12"

  // 1. Tạo đối tượng Square
  Square *square = new Square();

  // 2. Cắt chuỗi (để an toàn, dù chỉ có 1 thuộc tính)
  vector<string> tokens = Utils::String::split(data, ",");

  for (string &token : tokens) {
    int splitPos = token.find("=");
    if (splitPos == string::npos)
      continue;

    string key = token.substr(0, splitPos);
    string valueStr = token.substr(splitPos + 1);

    // 3. Tìm key "a" (cạnh hình vuông)
    if (key.find("a") != string::npos) {
      square->setSide(stof(valueStr)); // Giả sử hàm set cạnh là setSide
    }
  }

  return square;
}
SquareParser::SquareParser() {
  // Do nothing
}
string SquareParser::toString() { return "Square"; }