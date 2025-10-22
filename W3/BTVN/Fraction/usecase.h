#ifndef _USECASE_H_
#define _USECASE_H_

#include "Fraction.h"
#include <expected>
#include <tuple>
#include <string>
#include <iostream>
using std::expected, std::unexpected;
using std::string;
using std::tuple, std::make_tuple;
using std::cout, std::cin;

/**
 * @brief Lấy đầu vào hai phân số từ người dùng.
 *
 * Hàm này chịu trách nhiệm gọi hàm nhập liệu (thông qua lớp Fraction)
 * để yêu cầu người dùng nhập vào hai phân số.
 * Kết quả trả về có thể là hai phân số hợp lệ hoặc một thông báo lỗi.
 *
 * @return expected<tuple<Fraction, Fraction>, string>
 *         - Trả về `tuple<Fraction, Fraction>` nếu nhập thành công.
 *         - Trả về `unexpected(string)` nếu có lỗi (ví dụ: nhập sai hoặc mẫu số bằng 0).
 */
expected<tuple<Fraction, Fraction>, string> executeGetInputUseCase();

/**
 * @brief In thông điệp tạm biệt và kết thúc chương trình.
 *
 * Hàm này dùng để hiển thị lời chào tạm biệt, dọn dẹp (nếu cần),
 * và kết thúc chương trình một cách gọn gàng.
 */
void bye();

/**
 * @brief Tính và in ra tổng của hai phân số.
 *
 * Hàm nhận vào hai phân số, thực hiện phép cộng và hiển thị kết quả.
 * Không trả về giá trị, chỉ phục vụ cho việc xử lý và in ra kết quả.
 *
 * @param a Phân số thứ nhất.
 * @param b Phân số thứ hai.
 */
void executeCalcSumFractionsUseCase(const Fraction &a, const Fraction &b);

#endif 