#include "CalcPointsDistanceUseCase.h"

#include <iostream>
#include <format>
using std::cout, std::cin, std::endl;
using std::format;

#include "../dto/Point.h"
#include "../ui/Point.h"
#include "../bus/Point.h"

void CalcPointsDistanceUseCase::execute() {
    Point p1 = ui::requestPoint("Nhập vào điểm thứ nhất (theo định dạng x,y): ");
    Point p2 = ui::requestPoint("Nhập vào điểm thứ hai (theo định dạng x,y): ");

    float distance = bus::calcDistance(p1, p2);

    cout << format(
        "Khoảng cách từ điểm {} đến điểm {} là {}",
        ui::toString(p1), ui::toString(p2), distance
    );
}