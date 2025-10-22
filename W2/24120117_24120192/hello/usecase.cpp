#include "usecase.h"

void salute(std::string message)
{
    // TODO: Nếu chuỗi rỗng thì in ra thông báo mặc định
    std::cout << message;
}

void bye()
{
    std::cout << "\nChương trình đang thoát. Bấm enter để kết thúc..."; // 1 điểm
    std::cin.get();
}

void findNextDayUseCase()
{
    // Nhập thời gian
    int d, m, y;
    cout << "Nhập ngày: ";
    cin >> d;
    cout << "Nhập tháng: ";
    cin >> m;
    cout << "Nhập năm: ";
    cin >> y;

    // Kiểm tra tính hợp lệ của ngày tháng năm
    if (!checkDayMonthYear(d, m, y))
    {
        cout << "Ngày tháng năm không hợp lệ\n";
        return;
    }

    // Tạo ngày trong năm
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Kiểm tra năm nhuận
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        daysInMonth[1] = 29; // Tháng 2 có 29 ngày trong năm nhuận

    // Tính ngày kế tiếp
    d++;
    if (d > daysInMonth[m - 1])
    {
        d = 1;
        m++;
        if (m > 12)
        {
            m = 1;
            y++;
        }
    }
    cout << "Ngày tiếp theo là: " << d << "/" << m << "/" << y << "\n";
}

bool checkDayMonthYear(int d, int m, int y)
{
    //Kiểm tra tháng và năm hợp lệ 
    if (y < 1900 || m < 1 || m > 12)
        return false;
    //Kiểm tra ngày
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Kiểm tra năm nhuận
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        daysInMonth[1] = 29; // Tháng 2 có 29 ngày trong năm nhuận
    // kiểm tra ngày
    if (d < 1 || d > daysInMonth[m - 1])
        return false;
    return true;
}