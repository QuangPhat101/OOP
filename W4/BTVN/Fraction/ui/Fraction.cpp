#include "Fraction.h"

string ui::toString(const Fraction &frac)
{
    if (frac.getDenominator() == 1)
        return format("{}", frac.getNumerator());

    if (frac.getNumerator() > frac.getDenominator())
    {
        int wholePart = frac.getNumerator() / frac.getDenominator();
        int num = frac.getNumerator() - wholePart * frac.getDenominator();
        return format("{} {}/{}", wholePart, num, frac.getDenominator());
    }

    return format("{}/{}", frac.getNumerator(), frac.getDenominator());
}
expected<Fraction, string> ui::fromString(const string &str)
{
    if (str.empty())
        return unexpected("Invalid input data");

    regex pattern(R"(^\s*(-?\d+)\s*/\s*(-?\d+)\s*$)");
    smatch match;

    if (!regex_match(str, match, pattern))
        return unexpected("Invalid format data");

    int num = stoi(match[1].str());
    int deno = stoi(match[2].str());

    if (deno == 0)
        return unexpected("Denominator can not be zero");

    return Fraction(num, deno);
}
expected<Fraction, string> ui::requestFraction(string message)
{
    cout << message;
    string buffer;
    getline(cin, buffer);
    return ui::fromString(buffer);
}