#include <iostream>
#include <expected>
#include <tuple>
using std::cout, std::cin; // using namespace std;
using std::expected;
using std::tuple, std::make_tuple;

#include "main.h"
#include "Point.h"

// Từ class UseCase sẽ có hàm execute => Bản rút gọn chỉ có hàm Clean Architecture
expected<tuple<Point, Point>, string> executeGetInputUseCase();
void executeCaclPointsDistanceUseCase(const Point& a, const Point& b);


int main()
{
    cout << "Chương trình tính khoảng cách giữa hai điểm\n";
    
    // TODO: Chưa unit test
    auto result = executeGetInputUseCase();
    if (result.has_value()) {
        auto [start, end] = result.value();
        executeCaclPointsDistanceUseCase(start, end);
    } else {
        cout << result.error();
    }
    
    bye();
    return 0;
}

void bye() {
    cout << "\nChương trình đang thoát. Bấm enter để kết thúc...";
    cin.get();
}

expected<tuple<Point, Point>, string> executeGetInputUseCase() {
    auto result = Point::getPoint("Nhập điểm bắt đầu."); 
    if (!result.has_value()) {
        return unexpected(result.error());
    }
    Point start = result.value();
    
    result = Point::getPoint("Nhập điểm kết thúc.");
    if (!result.has_value()) {
        return unexpected(result.error());
    }
    Point end = result.value();
    
    return make_tuple(start, end);
}

void executeCaclPointsDistanceUseCase(const Point& a, const Point& b) {
    float distance = Point::distance(a, b);
    cout << "Khoảng cách giữa hai điểm "; // TODO: toString
    a.output();
    cout << " và điểm " ;
    b.output();
    cout << " là: " << distance;
}