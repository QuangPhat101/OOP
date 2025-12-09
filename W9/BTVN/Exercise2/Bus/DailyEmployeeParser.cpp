#include "DailyEmployeeParser.h"

DailyEmployeeParser::DailyEmployeeParser() {
  // Do nothing
}
DailyEmployee *DailyEmployeeParser::parse(string data) {
  // data có dạng: "dayCount=20, paymentPerPay=1000000"

  // 1. Dùng Utils::String::split để cắt chuỗi dựa trên dấu phẩy
  vector<string> tokens = Utils::String::split(data, ",");

  // 2. Tạo đối tượng
  DailyEmployee *employee = new DailyEmployee();

  // 3. Duyệt qua các token để lấy giá trị
  // Token ví dụ: "dayCount=20" hoặc " paymentPerPay=1000000" (có dấu cách thừa
  // ở đầu)
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
    // Lưu ý: key có thể chứa khoảng trắng thừa (ví dụ " paymentPerPay"),
    // nên ta dùng find thay vì so sánh bằng (==) để an toàn hơn.
    if (key.find("dayCount") != string::npos) {
      employee->setDayCount(stoi(valueStr));
    } else if (key.find("paymentPerPay") != string::npos) {
      employee->setPaymentPerDay(stoi(valueStr));
    }
  }

  return employee;
}
string DailyEmployeeParser::toString() { return "DailyEmployeeParser"; }