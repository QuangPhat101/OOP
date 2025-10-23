#include "Fraction.h"

// Hàm tạo
Fraction::Fraction()
{
    _numerator = 0;
    _denominator = 1;
}
Fraction::Fraction(int numerator, int denominator)
{
    this->_numerator = numerator;
    this->_denominator = denominator;
}
Fraction::~Fraction()
{
    // Destructor code (
}

// Hàm hủy
Fraction::Fraction(int integer)
{
    _numerator = integer;
    _denominator = 1;
}

// Hàm get
int Fraction::getNumerator() const
{
    return this->_numerator;
}
int Fraction::getDenominator() const
{
    return this->_denominator;
}

// Hàm set
void Fraction::setNumerator(int numerator)
{
    this->_numerator = numerator;
}
void Fraction::setDenominator(int denominator)
{
    this->_denominator = denominator;
}
