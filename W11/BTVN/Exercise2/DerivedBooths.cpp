#include "DerivedBooths.h"
#include <format> // C++20

constexpr auto ROW_FORMAT =
    "| {:<6} | {:<10} | {:>3} m2 | {:>9} | {:>13} | {:>11} | {:>13}";

string FoodBooth::toString() const {
  return std::format(ROW_FORMAT, id, "Thuc pham", (int)area,
                     formatMoney((long long)baseRate),
                     formatMoney(getBaseRent()), formatMoney(coldStorageFee),
                     formatMoney(calculateRent()));
}

string ClothesBooth::toString() const {
  return std::format(ROW_FORMAT, id, "Quan ao", (int)area,
                     formatMoney((long long)baseRate),
                     formatMoney(getBaseRent()),
                     "0", // Phí khác
                     formatMoney(calculateRent()));
}

string JewelryBooth::toString() const {
  return std::format(ROW_FORMAT, id, "Da qui", (int)area,
                     formatMoney((long long)baseRate),
                     formatMoney(getBaseRent()), formatMoney(securityFee),
                     formatMoney(calculateRent()));
}