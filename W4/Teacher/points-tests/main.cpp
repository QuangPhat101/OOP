#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <format>
using std::cin, std::cout;
using std::istringstream, std::ostringstream;
using std::format;

#include "../points/dto/Point.h"
#include "../points/ui/Point.h"
#include "../points/bus/Point.h"
#include "../points/usecase/CalcPointsDistanceUseCase.h"

// Test suite => tập hợp các test case
class PointTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(PointTest, DefaultConstructorCreatesOrigin) {
    Point p;
    EXPECT_FLOAT_EQ(0.0f, p.getX()); // Expected vs Actual
    EXPECT_FLOAT_EQ(0.0f, p.getY());
}

TEST_F(PointTest, TwoParameterConstructorSetsCoordinates) {
    Point p(3.5f, 4.2f);
    EXPECT_FLOAT_EQ(3.5f, p.getX());
    EXPECT_FLOAT_EQ(4.2f, p.getY());
}

class PointUITest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(PointUITest, ToStringOriginPoint) {
    Point p(0.0f, 0.0f);
    string result = ui::toString(p);
    EXPECT_FALSE(result.empty());
    // Result should contain coordinate values
}

TEST_F(PointUITest, ToStringPositiveCoordinates) {
    Point p(3.5f, 4.2f);
    string result = ui::toString(p);
    EXPECT_FALSE(result.empty());
    // Should contain both coordinate values
    EXPECT_NE(string::npos, result.find("3.5"));
    EXPECT_NE(string::npos, result.find("4.2"));
}

class CalcPointsDistanceUseCaseTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(CalcPointsDistanceUseCaseTest, OutputsCorrectMessage_For_Decimals) {
    Point p1(1.5f, 2.5f); 
    Point p2(4.0f, 6.0f);
    float distance = bus::calcDistance(p1, p2);

    string p1String = ui::toString(p1);
    string p2String = ui::toString(p2);
    string p1Input = p1String.substr(1, p1String.length() - 2);
    string p2Input = p2String.substr(1, p2String.length() - 2);
    cout << "Input 1:" << p1Input << "\n";
    cout << "Input 2:" << p2Input << "\n";

    istringstream input(format("{}\n{}\n",
        p1Input, p2Input
    ));
    ostringstream output;

    // Redirect stream cho cin và cout
    auto* cinBuf = cin.rdbuf();
    auto* coutBuf = cout.rdbuf();
    cin.rdbuf(input.rdbuf());
    cout.rdbuf(output.rdbuf());

    CalcPointsDistanceUseCase usecase;
    usecase.execute();

    // Phục hồi lại input output cho cin, cout
    cin.rdbuf(cinBuf);
    cout.rdbuf(coutBuf);

    std::string expected = std::format(
        "Khoảng cách từ điểm {} đến điểm {} là {}",
        p1String, p2String, distance
    );
    EXPECT_NE(output.str().find(expected), std::string::npos);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}