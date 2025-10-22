#include <gtest/gtest.h>
#include "../hello/usecase.h"

#include <sstream>
#include <format>

using std::istringstream, std::ostringstream;
using std::cout, std::cin;
using std::format;
using std::string;

bool executeCalcDMY(int day, int month, int year, int updated_day, int updated_month, int updated_year) {
    istringstream input(format("{}\n{}\n{}\n",
        day, month, year
    ));
    ostringstream output;

    auto* cinBuf = cin.rdbuf();
    auto* coutBuf = cout.rdbuf();
    cin.rdbuf(input.rdbuf());
    cout.rdbuf(output.rdbuf());

    findNextDayUseCase();
    cin.rdbuf(cinBuf);
    cout.rdbuf(coutBuf);
    
    string info = format("{}/{}/{}",
        updated_day, updated_month, updated_year
    );

    bool result = output.str().find(info) != string::npos;
    return result;
}

//False test case
TEST(findNextDayUseCase, ReturnsUpdatedDayMonthYear1) {
    int day = 1;
    int month = 1;
    int year = 1899;

    bool found = executeCalcDMY(day, month, year, 1, 1, 1899);
    EXPECT_EQ(found, false);
}

TEST(findNextDayUseCase, ReturnsUpdatedDayMonthYear2) {
    int day = 1;
    int month = 0;
    int year = 2025;

    bool found = executeCalcDMY(day, month, year, 1, 0, 2025);
    EXPECT_EQ(found, false);
}

TEST(findNextDayUseCase, ReturnsUpdatedDayMonthYear3) {
    int day = 1;
    int month = 13;
    int year = 2025;

    bool found = executeCalcDMY(day, month, year, 1, 13, 2025);
    EXPECT_EQ(found, false);
}

TEST(findNextDayUseCase, ReturnsUpdatedDayMonthYear4) {
    int day = 0;
    int month = 1;
    int year = 1899;

    bool found = executeCalcDMY(day, month, year, 0, 1, 1899);
    EXPECT_EQ(found, false);
}

TEST(findNextDayUseCase, ReturnsUpdatedDayMonthYear5) {
    int day = 29;
    int month = 2;
    int year = 2025;

    bool found = executeCalcDMY(day, month, year, 29, 2, 2025);
    EXPECT_EQ(found, false);
}

TEST(findNextDayUseCase, ReturnsUpdatedDayMonthYear6) {
    int day = 31;
    int month = 4;
    int year = 1975;

    bool found = executeCalcDMY(day, month, year, 31, 4, 1975);
    EXPECT_EQ(found, false);
}

//True test case
TEST(findNextDayUseCase, ReturnsUpdatedDayMonthYear7) {
    int day = 1;
    int month = 1;
    int year = 2025;

    bool found = executeCalcDMY(day, month, year, 2, 1, 2025);
    EXPECT_EQ(found, true);
}

TEST(findNextDayUseCase, ReturnsUpdatedDayMonthYear8) {
    int day = 28;
    int month = 2;
    int year = 2000;

    bool found = executeCalcDMY(day, month, year, 29, 2, 2000);
    EXPECT_EQ(found, true);
}

TEST(findNextDayUseCase, ReturnsUpdatedDayMonthYear9) {
    int day = 28;
    int month = 2;
    int year = 2001;

    bool found = executeCalcDMY(day, month, year, 1, 3, 2001);
    EXPECT_EQ(found, true);
}

TEST(findNextDayUseCase, ReturnsUpdatedDayMonthYear10) {
    int day = 30;
    int month = 4;
    int year = 1975;

    bool found = executeCalcDMY(day, month, year, 1, 5, 1975);
    EXPECT_EQ(found, true);
}

TEST(findNextDayUseCase, ReturnsUpdatedDayMonthYear11) {
    int day = 31;
    int month = 12;
    int year = 2025;

    bool found = executeCalcDMY(day, month, year, 1, 1, 2026);
    EXPECT_EQ(found, true);
}

// Nếu bạn không viết hàm main, thì nó sẽ được tự động sinh ra
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}