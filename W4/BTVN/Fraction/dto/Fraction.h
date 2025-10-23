#ifndef _FRACTION_H_
#define _FRACTION_H_

/**
 * @brief Lớp Fraction biểu diễn một phân số với tử số và mẫu số nguyên.
 * 
 * Lớp này cho phép tạo và quản lý phân số, với các thao tác cơ bản như:
 * - Khởi tạo phân số từ số nguyên hoặc cặp tử/mẫu
 * - Truy xuất và thay đổi tử số, mẫu số
 * - Đảm bảo mẫu số khác 0 khi khởi tạo và thiết lập
 */
class Fraction
{
private:
    int _numerator;   // Tử số
    int _denominator; // Mẫu số
public:
    /**
     * @brief Khởi tạo phân số mặc định 0/1
     */
    Fraction();

    /**
     * @brief Khởi tạo phân số với tử số và mẫu số cho trước
     * @param numerator Tử số
     * @param denominator Mẫu số (phải khác 0)
     * @throw std::invalid_argument nếu mẫu số bằng 0
     */
    Fraction(int numerator, int denominator);

    /**
     * @brief Khởi tạo phân số từ số nguyên (mẫu số = 1)
     * @param integer Giá trị nguyên cần chuyển thành phân số
     */
    Fraction(int integer);

    /**
     * @brief Hủy đối tượng phân số
     */
    ~Fraction();

public:
    /**
     * @brief Lấy giá trị tử số
     * @return Tử số hiện tại của phân số
     */
    int getNumerator() const;

    /**
     * @brief Lấy giá trị mẫu số
     * @return Mẫu số hiện tại của phân số
     */
    int getDenominator() const;

    /**
     * @brief Đặt giá trị cho tử số
     * @param numerator Tử số mới cần thiết lập
     */
    void setNumerator(int numerator);

    /**
     * @brief Đặt giá trị cho mẫu số
     * @param denominator Mẫu số mới (phải khác 0)
     * @throw std::invalid_argument nếu mẫu số bằng 0
     */
    void setDenominator(int denominator);
};

#endif