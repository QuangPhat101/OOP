#include <gtest/gtest.h>

#include "../Fraction/bus/Fraction.h"
#include "../Fraction/dto/Fraction.h"
#include "../Fraction/ui/Fraction.h"
#include "../Fraction/usecase/CalcSumFractionsUseCase.h"


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

// CalcSumFractions tests

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


int main(int argc, char**argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}