#include "usecase.h"

void bye()
{
    cout << "\nChương trình đang thoát. Bấm enter để kết thúc...";
    cin.get();
}

expected<tuple<Fraction, Fraction>, string> executeGetInputUseCase()
{
    auto result = Fraction::getFraction("-> Nhập phân số thứ nhất (dưới dạng a/b): ");
    if (!result.has_value())
    {
        return unexpected(result.error());
    }
    Fraction a = result.value();

    result = Fraction::getFraction("-> Nhập phân số thứ hai (dưới dạng a/b): ");
    if (!result.has_value())
    {
        return unexpected(result.error());
    }
    Fraction b = result.value();

    return make_tuple(a, b);
}

void executeCalcSumFractionsUseCase(const Fraction &a, const Fraction &b)
{
        cout << "Tổng của 2 phân số ";
        a.output();
        cout << " và ";
        b.output();
        cout << " là: ";
        auto result = Fraction::sumFraction(a, b);
        result.resultOutput();
}