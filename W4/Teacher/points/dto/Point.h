#ifndef _POINT_H_
#define _POINT_H_
#include <string>
using std::string;

/**
 * @brief Lớp biểu diễn một điểm 2D với tọa độ thực (x, y).
 *
 * Cung cấp getter/setter, nhiều constructor và destructor mặc định.
 */
class Point {
private: // attributes / backup field
    /**
     * @brief Tọa độ trục X.
     */
    float _x;
    /**
     * @brief Tọa độ trục Y.
     */
    float _y;
public: // properties
    /**
     * @brief Lấy giá trị tọa độ X.
     * @return Giá trị X hiện tại.
     */
    float getX() const;
    /**
     * @brief Lấy giá trị tọa độ Y.
     * @return Giá trị Y hiện tại.
     */
    float getY() const;
    /**
     * @brief Gán giá trị tọa độ X.
     * @param value Giá trị X mới.
     */
    void setX(float value);
    /**
     * @brief Gán giá trị tọa độ Y.
     * @param value Giá trị Y mới.
     */
    void setY(float value);
public: // Constructors / Destructors
    /**
     * @brief Tạo điểm tại gốc tọa độ (0, 0).
     */
    Point(); 
    /**
     * @brief Tạo điểm với tọa độ chỉ định.
     * @param x Tọa độ X.
     * @param y Tọa độ Y.
     */
    Point(float x, float y);
    /**
     * @brief Tạo điểm với X chỉ định và Y = 0.
     * @param x Tọa độ X.
     */
    Point(float x); 
    /**
     * @brief Hủy đối tượng Point.
     */
    ~Point();
};

#endif