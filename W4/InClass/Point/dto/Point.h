#ifndef _POINT_H
#define _POINT_H
#include <string>
using std::string;

class Point
{
private: // attribute / backup field : thuộc tính
    float _x;
    float _y;

public: // Properties
    /**
     * Lớp Point đại diện cho một điểm trong hệ tọa độ 2D.
     *
     * Thuộc tính:
     *  - _x: hoành độ (float)
     *  - _y: tung độ (float)
     *
     * Ý định sử dụng: lớp cung cấp các phương thức truy xuất (get/set),
     * các constructor để khởi tạo và một phương thức `toString` để lấy
     * biểu diễn chuỗi của điểm.
     */
    // Hàm set
    void setX(float x);
    void setY(float y);
    // Hàm get
    float getX() const;
    float getY() const;

public: // constructor / destructor
    // hàm sinh (không viết thì tự sinh)
    /**
     * Khởi tạo Point mặc định (0,0).
     */
    Point(); // Parameterless constructor
    /**
     * Khởi tạo Point với hoành độ x, tung độ y mặc định 0.
     * @param x Giá trị hoành độ.
     */
    Point(float x); // Parameterize constructor
    /**
     * Khởi tạo Point với hoành độ và tung độ cụ thể.
     * @param x Hoành độ.
     * @param y Tung độ.
     */
    Point(float x, float y);
    // hàm hủy
    ~Point();

public:
    /**
     * Trả về biểu diễn chuỗi của Point.
     *
     * Mặc định có thể trả về dưới dạng "x y" hoặc "(x,y)" tùy
     * cách triển khai trong .cpp.
     *
     * @return Chuỗi mô tả Point.
     */
    string toString(); // đây là hành vi của class nên cần phải có đối tượng cụ thể để gọi, ví dụ như a.toString()
};

#endif