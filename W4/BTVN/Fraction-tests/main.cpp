#include <gtest/gtest.h>

#include "../Fraction/bus/Fraction.h"
#include "../Fraction/dto/Fraction.h"
#include "../Fraction/ui/Fraction.h"
#include "../Fraction/usecase/CalcSumFractionsUseCase.h"



int main(int argc, char**argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}