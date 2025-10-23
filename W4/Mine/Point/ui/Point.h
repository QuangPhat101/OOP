#ifndef _POINT_UI_H
#define _POINT_UI_H
#include <string>
#include "../dto/Point.h"
using std::string;

namespace ui{
    /**
     * Chuyển một Point sang chuỗi mô tả.
     *
     * Mục đích: tạo biểu diễn dạng văn bản của đối tượng Point để hiển thị
     * hoặc ghi vào file. Cú pháp chuỗi phụ thuộc vào lớp dto::Point (ví dụ
     * "x y" hoặc "(x,y)").
     *
     * Tham số:
     *  - p: tham chiếu hằng tới Point cần chuyển.
     * Trả về:
     *  - Chuỗi mô tả Point.
     */
    string toString(const Point& p);

    /**
     * Chuyển chuỗi thành Point.
     *
     * Mục đích: phân tích (parse) một chuỗi và tạo đối tượng Point tương ứng.
     * Chuỗi đầu vào nên tuân theo định dạng mà toString tạo ra. Hàm này không
     * ném ngoại lệ; nếu chuỗi không hợp lệ, hành vi có thể trả về Point mặc
     * định (0,0) hoặc giá trị tùy triển khai trong `dto::Point`.
     *
     * Tham số:
     *  - str: chuỗi mô tả Point.
     * Trả về:
     *  - Point được tạo từ chuỗi.
     */
    Point fromString(const string& str);

    /**
     * Yêu cầu người dùng nhập một Point với thông báo.
     *
     * Mục đích: hiển thị `message` tới người dùng (ví dụ trên console),
     * đọc chuỗi đầu vào, sau đó phân tích thành `Point` bằng `fromString`.
     * Hàm sẽ lặp (hoặc yêu cầu lại) cho tới khi nhận được dữ liệu hợp lệ
     * tùy theo cách triển khai trong .cpp. Ở mức khai báo, hàm trả về Point
     * đã nhập.
     *
     * Tham số:
     *  - message: thông báo/nhắc cho người dùng.
     * Trả về:
     *  - Point người dùng đã nhập.
     */
    Point requestPoint(string message);
};

#endif