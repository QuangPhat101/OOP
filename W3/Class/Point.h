#ifndef _POINT_H_
#define _POINT_H_
#include <expected>
#include <string>
using std::expected, std::unexpected;
using std::string;

/**
 * @class Point
 * @brief Lớp biểu diễn một điểm trong hệ tọa độ 2D.
 * 
 * Lớp này bao gồm hai thuộc tính riêng (_x và _y) 
 * cùng với các phương thức để nhập/xuất tọa độ, 
 * và hàm tĩnh để tính khoảng cách giữa hai điểm.
 */
class Point {
private:
    float _x;  ///< Hoành độ (tọa độ x) của điểm
    float _y;  ///< Tung độ (tọa độ y) của điểm

public:
    /**
     * @brief Nhập tọa độ của điểm từ bàn phím.
     * 
     * Yêu cầu người dùng nhập hai giá trị float tương ứng với x và y.
     * @note Phương thức này thay đổi giá trị của thuộc tính `_x` và `_y`.
     */
    static expected<Point, string> getPoint(string message);

    /**
     * @brief Xuất tọa độ điểm ra màn hình.
     * 
     * In ra theo định dạng (x, y).
     */
    void output() const;

    /**
     * @brief Tính khoảng cách giữa hai điểm.
     * 
     * @param start Điểm thứ nhất (điểm bắt đầu)
     * @param end   Điểm thứ hai (điểm kết thúc)
     * @return float Khoảng cách Euclid giữa hai điểm
     * 
     * @details
     * Sử dụng công thức:
     * \f[
     * d = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}
     * \f]
     * 
     * @note Đây là hàm tĩnh (static), có thể gọi mà không cần tạo đối tượng:
     * @code
     * float d = Point::distance(A, B);
     * @endcode
     */
    static float distance(Point start, Point end);
};

#endif // POINT_H
