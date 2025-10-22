#ifndef _POINT_UI_H_
#define _POINT_UI_H_
#include <string>
using std::string;

#include "../dto/Point.h"

namespace ui {
    /**
     * @brief Tạo biểu diễn chuỗi cho một điểm.
     *
     * @param point Điểm nguồn cần chuyển thành chuỗi.
     * @return Chuỗi mô tả điểm. Nên dùng định dạng tương thích với fromString().
     * @note Kết quả nên có thể được phân tích lại bởi fromString().
     */
    string toString(const Point& point);

    /**
     * @brief Phân tích chuỗi để tạo một Point.
     *
     * @param str Chuỗi đầu vào cần phân tích.
     * @return Đối tượng Point tương ứng với chuỗi.
     * @throws std::invalid_argument nếu chuỗi không đúng định dạng (tùy triển khai).
     * @note Định dạng chuỗi cần đồng nhất với toString().
     */
    Point fromString(const string& str);

    /**
     * @brief Yêu cầu người dùng nhập một Point từ stdin.
     *
     * @param message Thông điệp hiển thị khi yêu cầu nhập.
     * @return Point người dùng đã nhập hợp lệ.
     * @note Triển khai có thể lặp lại cho đến khi đầu vào hợp lệ.
     */
    Point requestPoint(string message);
};

#endif