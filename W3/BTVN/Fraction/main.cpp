#include "Fraction.h"
#include "Int.h"
#include "usecase.h"

int main()
{
    cout << "- Chương trình tính tổng của 2 phân số\n";

    auto result = executeGetInputUseCase();
    if (result.has_value())
    {
        auto [a, b] = result.value();
        executeCalcSumFractionsUseCase(a, b);
    }
    else
    {
        cout << result.error();
    }

    bye();
    
    return 0;
}


