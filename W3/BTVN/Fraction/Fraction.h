#ifndef _FRACTION_H_
#define _FRACTION_H_
#include <expected>
#include <string>
#include <iostream>
#include <math.h>
using std::cout, std::cin;
using std::expected, std::unexpected;
using std::string;

/**
 * @class Fraction
 * @brief Lớp biểu diễn một phân số (tử và mẫu).
 *
 * Lớp này hỗ trợ nhập, xuất và thực hiện một số phép toán cơ bản với phân số.
 */
class Fraction
{
private:
    int numerator;   ///< Tử số của phân số
    int denominator; ///< Mẫu số của phân số

public:
    /**
     * @brief Nhập một phân số từ người dùng.
     *
     * Hàm hiển thị thông báo yêu cầu người dùng nhập phân số và kiểm tra tính hợp lệ.
     * Nếu nhập sai (ví dụ mẫu bằng 0), hàm trả về lỗi dưới dạng @c std::string.
     *
     * @param message Chuỗi thông báo hướng dẫn người dùng nhập dữ liệu.
     * @return std::expected<Fraction, std::string>
     *         - Trả về một đối tượng Fraction nếu nhập hợp lệ.
     *         - Trả về lỗi dạng chuỗi nếu nhập không hợp lệ.
     */
    static std::expected<Fraction, std::string> getFraction(std::string message);

    /**
     * @brief Xuất phân số ra màn hình.
     *
     * In ra tử và mẫu của phân số theo định dạng "numerator/denominator".
     */
    void output() const;

    /**
     * @brief In ra giá trị của phân số.
     *
     * Hiển thị phân số theo định dạng phù hợp:
     * - **"numerator/denominator"** nếu là phân số thông thường.
     * - **"a b/c"** nếu có thể biểu diễn dưới dạng hỗn số.
     * - **"a"** nếu phân số rút gọn thành số nguyên.
     *
     */

    void resultOutput() const;
    /**
     * @brief Tính tổng hai phân số.
     *
     * Thực hiện phép cộng hai phân số và trả về kết quả ở dạng số thực.
     *
     * @param a Phân số thứ nhất.
     * @param b Phân số thứ hai.
     * @return Fraction Kết quả của phép cộng hai phân số.
     */
    static Fraction sumFraction(Fraction a, Fraction b);

    /**
     * @brief Rút gọn phân số tổng.
     *
     * Thực hiện phép rút gọn phân số về dạng tối giản hoặc hỗn số.
     *
     * @param fraction Phân số cần rút gọn.
     * @return Fraction Phân số đã được rút gọn thành tối giản hoặc hỗn số.
     */
    static Fraction reduceFraction(Fraction fraction);

    /**
     * @brief Constructor khởi tạo một phân số với tử và mẫu mặc định để làm unit test.
     *
     * @param num Tử số của phân số (mặc định là 0).
     * @param den Mẫu số của phân số (mặc định là 1).
     */
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {}
};

#endif
