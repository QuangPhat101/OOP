#include "ManagerParser.h"

ManagerParser::ManagerParser() {
  // Do nothing
}

Manager *ManagerParser::parse(string data) {
  // data có dạng: "employeeCount=10, paymentPerEmployee=200000,
  // baseSalary=5000000"

  // 1. Dùng Utils::String::split để cắt chuỗi dựa trên dấu phẩy
  vector<string> tokens = Utils::String::split(data, ",");

  // 2. Tạo đối tượng
  Manager *manager = new Manager();

  // 3. Duyệt qua các token để lấy giá trị
  // Token ví dụ: "employeeCount=10" hoặc " paymentPerEmployee=200000" (có dấu
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
    // Lưu ý: key có thể chứa khoảng trắng thừa (ví dụ " paymentPerEmployee"),
    // nên ta dùng find thay vì so sánh bằng (==) để an toàn hơn.
    if (key.find("employeeCount") != string::npos) {
      manager->setEmployeeCount(stoi(valueStr));
    } else if (key.find("paymentPerEmployee") != string::npos) {
      manager->setPaymentPerEmployee(stoi(valueStr));
    } else if (key.find("baseSalary") != string::npos) {
      manager->setBaseSalary(stoi(valueStr));
    }
  }

  return manager;
}
string ManagerParser::toString() { return "ManagerParser"; }