#include <gtest/gtest.h>
#include "../Fraction/Fraction.h"
#include "../Fraction/Int.h"
#include "../Fraction/usecase.h"

#include <sstream>
#include <string>
using std::string;
using std::stringstream, std::ostringstream;
using std::cout;

bool executeCalcSum(int a_num, int a_den, int b_num, int b_den,
                    int expected_num, int expected_den)
{
    Fraction a(a_num, a_den);
    Fraction b(b_num, b_den);

    ostringstream output;
    std::streambuf *originalCoutBuffer = cout.rdbuf();
    cout.rdbuf(output.rdbuf());

    executeCalcSumFractionsUseCase(a, b);

    cout.rdbuf(originalCoutBuffer);

    string result = output.str();

    bool foundNum = result.find(std::to_string(expected_num)) != string::npos;
    bool foundDen = result.find(std::to_string(expected_den)) != string::npos;

    return foundNum && foundDen;
}

//True test cases

TEST(executeCalcSumFractionsUseCase, Sum_ValidSimple)
{
    // Test: 1/2 + 1/3 = 5/6
    int a_num = 1, a_den = 2;
    int b_num = 1, b_den = 3;
    int expected_num = 5, expected_den = 6;
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, true);
}

TEST(executeCalcSumFractionsUseCase, Sum_SameDenominator)
{
    // Test: 1/4 + 2/4 = 3/4
    int a_num = 1, a_den = 4;
    int b_num = 2, b_den = 4;
    int expected_num = 3, expected_den = 4;
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, true);
}

TEST(executeCalcSumFractionsUseCase, Sum_WholeNumberResult)
{
    // Test: 3/2 + 1/2 = 4/2 = 2/1
    int a_num = 3, a_den = 2;
    int b_num = 1, b_den = 2;
    int expected_num = 2, expected_den = 1;
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, true);
}

TEST(executeCalcSumFractionsUseCase, Sum_ImproperFraction)
{
    // Test: 5/4 + 3/4 = 8/4 = 2/1
    int a_num = 5, a_den = 4;
    int b_num = 3, b_den = 4;
    int expected_num = 2, expected_den = 1;
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, true);
}

TEST(executeCalcSumFractionsUseCase, Sum_ReduceResult)
{
    // Test: 2/4 + 2/4 = 4/4 = 1/1 (phải rút gọn)
    int a_num = 2, a_den = 4;
    int b_num = 2, b_den = 4;
    int expected_num = 1, expected_den = 1;
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, true);
}

TEST(executeCalcSumFractionsUseCase, Sum_NegativeAndPositive)
{
    // Test: -1/4 + 3/4 = 2/4 = 1/2
    int a_num = -1, a_den = 4;
    int b_num = 3, b_den = 4;
    int expected_num = 1, expected_den = 2;
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, true);
}

TEST(executeCalcSumFractionsUseCase, Sum_BothNegative)
{
    // Test: -2/5 + -3/5 = -5/5 = -1/1
    int a_num = -2, a_den = 5;
    int b_num = -3, b_den = 5;
    int expected_num = -1, expected_den = 1;
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, true);
}

TEST(executeCalcSumFractionsUseCase, Sum_NegativeResult)
{
    // Test: 1/4 + -3/4 = -2/4 = -1/2
    int a_num = 1, a_den = 4;
    int b_num = -3, b_den = 4;
    int expected_num = -1, expected_den = 2;
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, true);
}

TEST(executeCalcSumFractionsUseCase, Sum_DenominatorNegative)
{
    // Test: 1/-2 + 1/2 = -1/2 + 1/2 = 0/1
    int a_num = 1, a_den = -2;
    int b_num = 1, b_den = 2;
    int expected_num = 0, expected_den = 1;
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, true);
}

// Special test cases
TEST(executeCalcSumFractionsUseCase, Sum_ResultIsZero)
{
    // Test: 1/3 + -1/3 = 0/3 = 0/1
    int a_num = 1, a_den = 3;
    int b_num = -1, b_den = 3;
    int expected_num = 0, expected_den = 1;
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, true);
}

TEST(executeCalcSumFractionsUseCase, Sum_ZeroNumerator)
{
    // Test: 0/5 + 2/5 = 2/5
    int a_num = 0, a_den = 5;
    int b_num = 2, b_den = 5;
    int expected_num = 2, expected_den = 5;
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, true);
}

TEST(executeCalcSumFractionsUseCase, Sum_BothZero)
{
    // Test: 0/1 + 0/1 = 0/1
    int a_num = 0, a_den = 1;
    int b_num = 0, b_den = 1;
    int expected_num = 0, expected_den = 1;
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, true);
}

TEST(executeCalcSumFractionsUseCase, Sum_OneIsZero)
{
    // Test: 0/1 + 3/4 = 3/4
    int a_num = 0, a_den = 1;
    int b_num = 3, b_den = 4;
    int expected_num = 3, expected_den = 4;
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, true);
}

TEST(executeCalcSumFractionsUseCase, Sum_LargeNumbers)
{
    // Test: 100/200 + 150/300 = 1/2 + 1/2 = 1/1
    int a_num = 100, a_den = 200;
    int b_num = 150, b_den = 300;
    int expected_num = 1, expected_den = 1;
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, true);
}

// False test case

TEST(executeCalcSumFractionsUseCase, Sum_WrongNumerator)
{
    // Test: 1/2 + 1/3 = 5/6
    int a_num = 1, a_den = 2;
    int b_num = 1, b_den = 3;
    int expected_num = 4, expected_den = 6; // SAI
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, false); 
}

TEST(executeCalcSumFractionsUseCase, Sum_WrongDenominator)
{
    // Test: 1/2 + 1/3 = 5/6
    int a_num = 1, a_den = 2;
    int b_num = 1, b_den = 3;
    int expected_num = 5, expected_den = 7; // SAI
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, false);
}

TEST(executeCalcSumFractionsUseCase, Sum_NotReduced)
{
    // Test: 2/4 + 2/4 = 1/1 = 1
    int a_num = 2, a_den = 4;
    int b_num = 2, b_den = 4;
    int expected_num = 4, expected_den = 4; // SAI 
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, false);
}

TEST(executeCalcSumFractionsUseCase, Sum_WrongSign)
{
    // Test: 1/4 + -3/4 = -1/2
    int a_num = 1, a_den = 4;
    int b_num = -3, b_den = 4;
    int expected_num = 1, expected_den = 2; // SAI 
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, false);
}

TEST(executeCalcSumFractionsUseCase, Sum_CompletelyWrong)
{
    // Test: 1/2 + 1/3 = 5/6
    int a_num = 1, a_den = 2;
    int b_num = 1, b_den = 3;
    int expected_num = 7, expected_den = 8; // SAI
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, false);
}

TEST(executeCalcSumFractionsUseCase, Sum_ZeroWhenNotZero)
{
    // Test: 1/4 + 2/4 = 3/4
    int a_num = 1, a_den = 4;
    int b_num = 2, b_den = 4;
    int expected_num = 0, expected_den = 1; // SAI 
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, false);
}

TEST(executeCalcSumFractionsUseCase, Sum_SwappedNumeratorDenominator)
{
    // Test: 2/3 + 1/3 = 3/3 = 1
    int a_num = 2, a_den = 3;
    int b_num = 1, b_den = 3;
    int expected_num = 3, expected_den = 1; // SAI 
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, false);
}

TEST(executeCalcSumFractionsUseCase, Sum_OffByOne)
{
    // Test: 1/5 + 2/5 = 3/5
    int a_num = 1, a_den = 5;
    int b_num = 2, b_den = 5;
    int expected_num = 4, expected_den = 5; // SAI 
    bool found = executeCalcSum(a_num, a_den, b_num, b_den, expected_num, expected_den);
    EXPECT_EQ(found, false);
}


TEST(executeCalcSumFractionsUseCase, Sum_InvalidDenominator)
{
    EXPECT_THROW(Fraction(1, 0), std::invalid_argument);
}

// ============================================================================
// Main function
// ============================================================================

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}