#ifndef _FRACTION_UI_H_
#define _FRACTION_UI_H_
#include <string>
#include <format>
#include <iostream>
#include <expected>
#include <regex>
#include <sstream>
using std::cout, std::cin;
using std::expected, std::unexpected;
using std::format;
using std::regex, std::regex_match, std::smatch;
using std::string;
using std::stringstream;
using std::endl;

#include "../dto/Fraction.h"

namespace ui
{

    /**
     * @brief Chuyển một Fraction thành chuỗi để hiển thị hoặc lưu.
     *
     * Ví dụ định dạng: "numerator/denominator" hoặc "integer".
     *
     * @param frac Tham chiếu hằng tới Fraction cần chuyển.
     * @return Chuỗi mô tả phân số.
     */
    string toString(const Fraction &frac);

    /**
     * @brief Phân tích chuỗi và trả về Fraction hoặc thông báo lỗi.
     *
     * Hàm trả về `std::expected<Fraction, string>`:
     * - Nếu phân tích thành công -> trả về `expected` có giá trị `Fraction`.
     * - Nếu chuỗi không hợp lệ hoặc mẫu số = 0 -> trả về `unexpected` chứa
     *   chuỗi mô tả lỗi (ví dụ "invalid format" hoặc "denominator is zero").
     *
     * @param str Chuỗi mô tả phân số.
     * @return expected chứa Fraction hoặc chuỗi lỗi.
     */
    expected<Fraction, string> fromString(const string &str);

    /**
     * @brief Yêu cầu người dùng nhập một Fraction qua console và trả về kết quả.
     *
     * Hàm hiển thị `message`, đọc dòng nhập của người dùng và gọi `fromString`.
     * Trả về `std::expected<Fraction, string>` tương tự: thành công có giá trị
     * Fraction, thất bại có chuỗi lỗi. Việc lặp yêu cầu khi lỗi hay không sẽ
     * phụ thuộc vào cách triển khai trong .cpp; ở mức khai báo, hàm chỉ trả
     * về kết quả phân tích một lần.
     *
     * @param message Thông báo/nhắc cho người dùng.
     * @return expected chứa Fraction hoặc chuỗi lỗi.
     */
    expected<Fraction, string> requestFraction(string message);
}
#endif