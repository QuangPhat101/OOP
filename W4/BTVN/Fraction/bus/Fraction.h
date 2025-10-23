#ifndef _FRACTION_BUS_H_
#define _FRACTION_BUS_H_
#include "../dto/Fraction.h"
#include <math.h>

namespace bus
{
    /**
     * @brief Tính tổng hai phân số và trả về phân số kết quả (không thay đổi tham số đầu vào).
     *
     * Hàm sẽ qui đồng mẫu số, cộng tử số, sau đó có thể rút gọn kết quả tùy theo
     * cách triển khai trong .cpp.
     *
     * @param frac1 Phân số thứ nhất (tham chiếu hằng)
     * @param frac2 Phân số thứ hai (tham chiếu hằng)
     * @return Fraction Phân số mới biểu diễn tổng frac1 + frac2
     */
    Fraction CalcSumFractions(const Fraction &frac1, const Fraction &frac2);

    /**
     * @brief Rút gọn (tối giản) phân số truyền vào (thay đổi trực tiếp đối tượng).
     *
     * Ví dụ: 2/4 -> 1/2. Hàm sửa mẫu số/tử số của `frac` để không còn ước chung lớn hơn 1.
     *
     * @param frac Tham chiếu đến phân số cần được rút gọn (in-place)
     */
    void getMinimalistFractions(Fraction &frac);
}

#endif