#include "ProductEmployeeParser.h"

ProductEmployeeParser::ProductEmployeeParser() {
  // Do nothing
}
ProductEmployee *ProductEmployeeParser::parse(string data) {
  // data có dạng: "productCount=50, paymentPerProduct=50000"

  // 1. Dùng Utils::String::split để cắt chuỗi dựa trên dấu phẩy
  vector<string> tokens = Utils::String::split(data, ",");

  // 2. Tạo đối tượng
  ProductEmployee *employee = new ProductEmployee();

  // 3. Duyệt qua các token để lấy giá trị
  // Token ví dụ: "productCount=50" hoặc " paymentPerProduct=50000" (có dấu
  // cách thừa ở đầu)
  for (string &token : tokens) {
    // Tìm vị trí dấu "="
    int splitPos = token.find("=");

    // Nếu không có dấu "=" thì bỏ qua (đề phòng lỗi dữ liệu)
    if (splitPos == string::npos)
      continue;

    // Lấy phần key (trước dấu =) và value (sau dấu =)
    // Dùng substr để cắt. start từ splitPos + 1 để bỏ qua dấu "="
    string key = token.substr(0, splitPos);
    string valueStr = token.substr(splitPos + 1);

    // Xử lý gán dữ liệu dựa trên key
    // Lưu ý: key có thể chứa khoảng trắng thừa (ví dụ " paymentPerProduct"),
    // nên ta dùng find thay vì so sánh bằng (==) để an toàn hơn.
    if (key.find("productCount") != string::npos) {
      employee->setProductCount(stoi(valueStr));
    } else if (key.find("paymentPerProduct") != string::npos) {
      employee->setPaymentPerProduct(stoi(valueStr));
    }
  }

  return employee;
}
string ProductEmployeeParser::toString() { return "ProductEmployeeParser"; }