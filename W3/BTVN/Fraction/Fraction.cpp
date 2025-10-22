#include "Fraction.h"
#include "Int.h"

expected<Fraction, string> Fraction::getFraction(string message)
{;
    auto result = Int::getInt(message);

    if (!result.has_value())
    {
        return unexpected(result.error());
    }
    return result.value();
}

void Fraction::output() const
{
    cout << numerator << "/" << denominator;
}

void Fraction::resultOutput() const
{
    //Mẫu số bằng 1
    if (denominator == 1)
    {
        cout << numerator << "\n";
        return;
    }
    // Hỗn số có dạng a b/c 
    if (numerator > denominator)
    {
        int a = numerator / denominator;
        int b = numerator % denominator;
        int c = denominator;
        cout << a << " " << b << "/" << c << "\n";
        return;
    }
    // Phân số thông thường
    cout << numerator << "/" << denominator << "\n";
}

Fraction Fraction::sumFraction(Fraction a, Fraction b)
{
    Fraction result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    result = reduceFraction(result);
    return result;
}

Fraction Fraction::reduceFraction(Fraction fraction)
{
    int a = abs(fraction.numerator);
    int b = abs(fraction.denominator);

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    if (a != 0)
    {
        fraction.numerator /= a;
        fraction.denominator /= a;
    }

    if (fraction.denominator < 0)
    {
        fraction.numerator = -fraction.numerator;
        fraction.denominator = -fraction.denominator;
    }

    return fraction;
}