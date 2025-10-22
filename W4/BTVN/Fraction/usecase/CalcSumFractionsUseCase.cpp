#include "CalcSumFractionsUseCase.h"
#include "../bus/Fraction.h"
#include "../dto/Fraction.h"
#include "../ui/Fraction.h"

void CalcSumFractionsUseCase::execute()
{
    auto result = ui::requestFraction("Nhập vào phân số đầu tiên dưới dạng a/b: ");
    if (!result.has_value())
    {
        cout << result.error();
        return;
    }

    Fraction frac1 = result.value();
    result = ui::requestFraction("Nhập vào phân số thứ hai dưới dạng a/b: ");
    if (!result.has_value())
    {
        cout << result.error();
        return;
    }
    Fraction frac2 = result.value();
    Fraction Sum = bus::CalcSumFractions(frac1, frac2);
    bus::getMinimalistFractions(Sum);
    cout << "Tổng của 2 phân số là: " << ui::toString(Sum);
}
