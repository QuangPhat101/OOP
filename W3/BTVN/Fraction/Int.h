#ifndef _INT_H_
#define _INT_H_
#include <string>
#include <expected>
#include <iostream>
#include <format>
#include <regex>
#include <sstream>
#include "Fraction.h"
using std::cout, std::cin;
using std::expected, std::unexpected;
using std::format;
using std::regex, std::regex_match;
using std::string, std::stringstream;

/**
 * @class Int
 * @brief Lớp hỗ trợ nhập dữ liệu số nguyên từ người dùng.
 *
 * Dùng để lấy các giá trị như tử số, mẫu số của phân số,
 * với cơ chế kiểm tra lỗi, nhập lại hoặc giới hạn số lần thử.
 */
class Int
{
public:
    /**
     * @brief Lấy giá trị số nguyên từ người dùng một lần.
     *
     * Hiển thị thông báo và đọc giá trị từ bàn phím.
     * Nếu người dùng nhập sai định dạng (không phải số nguyên),
     * hàm trả về lỗi dưới dạng chuỗi.
     *
     * @param message Chuỗi thông báo hiển thị cho người dùng.
     * @return expected<int, :string>
     *         - Trả về giá trị hợp lệ nếu nhập đúng.
     *         - Trả về lỗi (chuỗi) nếu nhập sai.
     */
    static expected<Fraction, string> getInt(string message);
};

#endif