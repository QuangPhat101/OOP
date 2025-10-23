#ifndef _POINT_BUS_H
#define _POINT_BUS_H

#include "../dto/Point.h"

namespace bus
{
    /**
     * @brief Tính khoảng cách Euclid giữa hai điểm 2D.
     *
     * @param p1 Điểm thứ nhất.
     * @param p2 Điểm thứ hai.
     * @return Khoảng cách giữa p1 và p2 (cùng đơn vị với tọa độ).
     * @note Công thức: sqrt((x2 - x1)^2 + (y2 - y1)^2).
     */
    float calcDistance(const Point &p1, const Point &p2);
};

#endif