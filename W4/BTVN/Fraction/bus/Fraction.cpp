#include "Fraction.h"

Fraction bus::CalcSumFractions(const Fraction &frac1, const Fraction &frac2)
{
    int num = frac1.getNumerator() * frac2.getDenominator() + frac2.getNumerator() * frac1.getDenominator();
    int deno = frac1.getDenominator() * frac2.getDenominator();
    return Fraction(num, deno);
}
void bus::getMinimalistFractions(Fraction &frac)
{
    int a = abs(frac.getNumerator());
    int b = abs(frac.getDenominator());

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    if (a != 0)
    {
        int num = frac.getNumerator();
        frac.setNumerator(num /= a);
        int deno = frac.getDenominator();
        frac.setDenominator(deno /= a);
    }

    if (frac.getDenominator() < 0)
    {
        frac.setNumerator(-frac.getNumerator());
        frac.setDenominator(-frac.getDenominator());
    }
}