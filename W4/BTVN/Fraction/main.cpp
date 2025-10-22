#include <iostream>
#include <string>
using std::cout, std::cin;
using std::string;

#include "usecase/CalcSumFractionsUseCase.h"

void salute(string message);
void bye();

int main()
{
    salute("Chương trình tính tổng 2 phân số\n");

    CalcSumFractionsUseCase useCase;
    useCase.execute();

    bye();
    return 0;
}

void salute(string message)
{
    cout << message;
}

void bye()
{
    cout << "\nChương trình đang thoát. Bấm Enter để kết thúc..";
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}