#include "DerivedBooths.h"
#include <algorithm>
#include <format>
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

int main() {
  const double BASE_RENT = 560000;
  vector<Booth *> booths;

  // Regex Patterns
  regex foodRegex(R"(Food ID=([^,]+),\s*Area=(\d+),\s*ColdStorage=(\d+))");
  regex clothesRegex(R"(Clothes ID=([^,]+),\s*Area=(\d+))");
  regex jewelryRegex(
      R"(Jewelry ID=([^,]+),\s*Area=(\d+),\s*SecurityFee=(\d+))");

  smatch matches;
  ifstream file("RentMay26.txt");

  if (!file.is_open()) {
    cerr << "Khong the mo file!" << endl;
    return 1;
  }

  string line;
  while (getline(file, line)) {
    if (regex_search(line, matches, foodRegex)) {
      booths.push_back(new FoodBooth(matches[1], stod(matches[2]), BASE_RENT,
                                     stoll(matches[3])));
    } else if (regex_search(line, matches, clothesRegex)) {
      booths.push_back(
          new ClothesBooth(matches[1], stod(matches[2]), BASE_RENT));
    } else if (regex_search(line, matches, jewelryRegex)) {
      booths.push_back(new JewelryBooth(matches[1], stod(matches[2]), BASE_RENT,
                                        stoll(matches[3])));
    }
  }
  file.close();

  sort(booths.begin(), booths.end(),
       [](Booth *a, Booth *b) { return a->getRent() < b->getRent(); });

  cout << "Bao cao thu tien thue mat bang cho Ben Thanh\nThang: 05/2024\n\n";

  string header = std::format(
      "{:<4} | {:<6} | {:<10} | {:<6} | {:<9} | {:<13} | {:<11} | {:<13}",
      "STT", "Ma sap", "Loai", "DTich", "Tien / m2", "Tien mat bang",
      "Phi khac", "Tong cong");

  cout << header << endl;
  cout << string(header.length(), '-') << endl;

  long long totalRevenue = 0;
  for (int i = 0; i < booths.size(); ++i) {
    cout << std::format("{:<4} {}", i + 1, booths[i]->toString()) << endl;
    totalRevenue += booths[i]->getRent();
  }

  cout << "\nTong tien thue mat bang thu trong thang: "
       << formatMoney(totalRevenue) << " d" << endl;

  // Dọn dẹp
  for (auto b : booths)
    delete b;

  return 0;
}