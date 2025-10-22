#include "Int.h"

expected<Fraction, string> Int::getInt(string message)
{
    cout << message;

    string buffer;
    getline(cin, buffer);

    // 1. Rỗng - Edge case
    if (buffer.length() == 0)
    {
        return unexpected("Empty input data");
    }

    // 2. Sai định dạng - Invalid format
    regex numberPattern(R"(^-?\d+(\/-?\d+)?$)");
    bool matched = regex_match(buffer, numberPattern);

    if (!matched)
    {
        return unexpected("Invalid value format");
    }
    char delimiter = '/';
    if (buffer.find(delimiter) == string::npos)
    {
        return unexpected("Invalid value format");
    }
    // 3. Sai miền giá trị
    int numerator = 0, denominator = 1;
    stringstream ss(buffer);
    ss >> numerator >> delimiter >> denominator;
    Fraction result(numerator, denominator);
    if (denominator == 0)
    {
        return unexpected("Denominator cannot be zero");
    }
    return result;
}
