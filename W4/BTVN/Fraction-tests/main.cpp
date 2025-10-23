#include <gtest/gtest.h>

#include "../Fraction/bus/Fraction.h"
#include "../Fraction/dto/Fraction.h"
#include "../Fraction/ui/Fraction.h"
#include "../Fraction/usecase/CalcSumFractionsUseCase.h"

//Fraction bus tests
TEST(FractionMinimalist, ReducePositive)
{
    Fraction f(2, 4);
    bus::getMinimalistFractions(f);
    EXPECT_EQ(f.getNumerator(), 1);
    EXPECT_EQ(f.getDenominator(), 2);
}

TEST(FractionMinimalist, NegativeDenominator)
{
    Fraction f(1, -2);
    bus::getMinimalistFractions(f);
    EXPECT_EQ(f.getNumerator(), -1);
    EXPECT_EQ(f.getDenominator(), 2);
}

TEST(FractionMinimalist, ZeroNumerator)
{
    Fraction f(0, 5);
    bus::getMinimalistFractions(f);
    EXPECT_EQ(f.getNumerator(), 0);
    EXPECT_EQ(f.getDenominator(), 1);
}

TEST(FractionMinimalist, AlreadyReduced)
{
    Fraction f(3, 7);
    bus::getMinimalistFractions(f);
    EXPECT_EQ(f.getNumerator(), 3);
    EXPECT_EQ(f.getDenominator(), 7);
}

TEST(FractionMinimalist, BothNegative)
{
    Fraction f(-2, -4);
    bus::getMinimalistFractions(f);
    EXPECT_EQ(f.getNumerator(), 1);
    EXPECT_EQ(f.getDenominator(), 2);
}

TEST(FractionMinimalist, LargeGCD)
{
    Fraction f(120, 90);
    bus::getMinimalistFractions(f);
    EXPECT_EQ(f.getNumerator(), 4);
    EXPECT_EQ(f.getDenominator(), 3);
}

TEST(FractionSum, SimpleAdd)
{
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction r = bus::CalcSumFractions(a, b);
    bus::getMinimalistFractions(r);
    EXPECT_EQ(r.getNumerator(), 5);
    EXPECT_EQ(r.getDenominator(), 6);
}

TEST(FractionSum, SumCancelToZero)
{
    Fraction a(-1, 2);
    Fraction b(1, 2);
    Fraction r = bus::CalcSumFractions(a, b);
    bus::getMinimalistFractions(r);
    EXPECT_EQ(r.getNumerator(), 0);
    EXPECT_EQ(r.getDenominator(), 1);
}

TEST(FractionSum, SumWithReduction)
{
    Fraction a(1, 4);
    Fraction b(1, 4);
    Fraction r = bus::CalcSumFractions(a, b);
    bus::getMinimalistFractions(r);
    EXPECT_EQ(r.getNumerator(), 1);
    EXPECT_EQ(r.getDenominator(), 2);
}
// End of Fraction bus tests

// Fraction DTO tests
TEST(FractionDTO, DefaultConstructor) {
    Fraction f;
    EXPECT_EQ(f.getNumerator(), 0) << "Default numerator should be 0";
    EXPECT_EQ(f.getDenominator(), 1) << "Default denominator should be 1";
}

TEST(FractionDTO, IntegerConstructor) {
    Fraction f(5);
    EXPECT_EQ(f.getNumerator(), 5);
    EXPECT_EQ(f.getDenominator(), 1);
}

TEST(FractionDTO, TwoArgConstructor) {
    Fraction f(2, 4);
    EXPECT_EQ(f.getNumerator(), 2);
    EXPECT_EQ(f.getDenominator(), 4);
}

TEST(FractionDTO, TwoArgConstructorDenominatorZeroThrows) {
    EXPECT_THROW({
        Fraction f(1, 0);
        (void)f;
    }, std::invalid_argument);
}

TEST(FractionDTO, SetDenominatorThrowsOnZero) {
    Fraction f;
    EXPECT_THROW(f.setDenominator(0), std::invalid_argument);
}

TEST(FractionDTO, SettersAndGetters) {
    Fraction f;
    f.setNumerator(7);
    f.setDenominator(3);
    EXPECT_EQ(f.getNumerator(), 7);
    EXPECT_EQ(f.getDenominator(), 3);

    // update again
    f.setNumerator(-10);
    f.setDenominator(2);
    EXPECT_EQ(f.getNumerator(), -10);
    EXPECT_EQ(f.getDenominator(), 2);
}
// End of Fraction DTO tests

// UI Fraction tests
TEST(UIFraction, ToString_Basic) {
    Fraction f1(3, 4);
    EXPECT_EQ(ui::toString(f1), "3/4");

    Fraction f2(5);
    EXPECT_EQ(ui::toString(f2), "5");

    Fraction f3(-2, 3);
    EXPECT_EQ(ui::toString(f3), "-2/3");
}

TEST(UIFraction, FromString_ValidInputs) {
    {
        auto res = ui::fromString("3/4");
        ASSERT_TRUE(res.has_value());
        EXPECT_EQ(res.value().getNumerator(), 3);
        EXPECT_EQ(res.value().getDenominator(), 4);
    }
    {
        auto res = ui::fromString("5");
        ASSERT_TRUE(res.has_value());
        EXPECT_EQ(res.value().getNumerator(), 5);
        EXPECT_EQ(res.value().getDenominator(), 1);
    }
    {
        auto res = ui::fromString("-2/3");
        ASSERT_TRUE(res.has_value());
        EXPECT_EQ(res.value().getNumerator(), -2);
        EXPECT_EQ(res.value().getDenominator(), 3);
    }
}

TEST(UIFraction, FromString_InvalidInputs) {
    {
        auto res = ui::fromString("1/0");
        EXPECT_FALSE(res.has_value());
        // Per documentation, expect an error mentioning denominator issue
        EXPECT_FALSE(res.error().empty());
        EXPECT_NE(res.error().find("denominator"), std::string::npos);
    }
    {
        auto res = ui::fromString("not a fraction");
        EXPECT_FALSE(res.has_value());
        EXPECT_FALSE(res.error().empty()); // invalid format message expected
    }
    {
        auto res = ui::fromString("3/"); // malformed
        EXPECT_FALSE(res.has_value());
        EXPECT_FALSE(res.error().empty());
    }
}

TEST(UIFraction, RequestFraction_ReadsFromCin_Success) {
    // Save original cin buffer
    std::streambuf* oldbuf = std::cin.rdbuf();
    {
        std::istringstream iss("7/8\n");
        std::cin.rdbuf(iss.rdbuf());
        auto res = ui::requestFraction("Enter fraction:");
        ASSERT_TRUE(res.has_value());
        EXPECT_EQ(res.value().getNumerator(), 7);
        EXPECT_EQ(res.value().getDenominator(), 8);
    }
    // Restore
    std::cin.rdbuf(oldbuf);
}

TEST(UIFraction, RequestFraction_ReadsFromCin_Invalid) {
    std::streambuf* oldbuf = std::cin.rdbuf();
    {
        std::istringstream iss("bad_input\n");
        std::cin.rdbuf(iss.rdbuf());
        auto res = ui::requestFraction("Enter fraction:");
        EXPECT_FALSE(res.has_value());
        EXPECT_FALSE(res.error().empty());
    }
    std::cin.rdbuf(oldbuf);
}
// End of UI Fraction tests

//CalcSumFractionsUseCase tests
TEST(CalcSumFractionsUseCase, Execute_PrintsSumForValidInput) {
    // Save original buffers
    std::streambuf* cin_buf = std::cin.rdbuf();
    std::streambuf* cout_buf = std::cout.rdbuf();

    std::istringstream input("1/2\n3/4\n");
    std::ostringstream output;

    std::cin.rdbuf(input.rdbuf());
    std::cout.rdbuf(output.rdbuf());

    CalcSumFractionsUseCase usecase;
    // Execute should not throw for valid input
    ASSERT_NO_THROW(usecase.execute());

    // Restore buffers
    std::cin.rdbuf(cin_buf);
    std::cout.rdbuf(cout_buf);

    std::string out = output.str();
    EXPECT_FALSE(out.empty());
    EXPECT_NE(out.find("5/4"), std::string::npos) << "Expected sum 5/4 to appear in output: " << out;
}

TEST(CalcSumFractionsUseCase, Execute_DoesNotThrowOnInvalidThenValid) {
    std::streambuf* cin_buf = std::cin.rdbuf();
    std::streambuf* cout_buf = std::cout.rdbuf();

    // first line invalid, then provide two valid fractions
    std::istringstream input("not a fraction\n7/8\n1/8\n");
    std::ostringstream output;

    std::cin.rdbuf(input.rdbuf());
    std::cout.rdbuf(output.rdbuf());

    CalcSumFractionsUseCase usecase;
    // The use-case should handle invalid input gracefully (no crash)
    ASSERT_NO_THROW(usecase.execute());

    std::cin.rdbuf(cin_buf);
    std::cout.rdbuf(cout_buf);

    std::string out = output.str();
    EXPECT_FALSE(out.empty());
}

TEST(CalcSumFractionsUseCase, Execute_HandlesIntegerInputs) {
    std::streambuf* cin_buf = std::cin.rdbuf();
    std::streambuf* cout_buf = std::cout.rdbuf();

    // integer-style inputs: "5" and "2" -> sum 7 (printed as "7")
    std::istringstream input("5\n2\n");
    std::ostringstream output;

    std::cin.rdbuf(input.rdbuf());
    std::cout.rdbuf(output.rdbuf());

    CalcSumFractionsUseCase usecase;
    ASSERT_NO_THROW(usecase.execute());

    std::cin.rdbuf(cin_buf);
    std::cout.rdbuf(cout_buf);

    std::string out = output.str();
    EXPECT_FALSE(out.empty());
    EXPECT_NE(out.find("7"), std::string::npos) << "Expected integer sum 7 in output: " << out;
}
// End of CalcSumFractionsUseCase tests

// Main 
int main(int argc, char**argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}