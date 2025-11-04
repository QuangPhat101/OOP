#include "utils.h"

expected<int, string> getInt(string message, int minValue, int maxValue)
{
    cout << message;
    string buffer;
    getline(cin, buffer);

    if (buffer.empty()) return unexpected("Empty input data");

    string pattern = R"(^-?\d+$)";
    if (!regex_match(buffer, regex(pattern)))
        return unexpected("Invalid format data");

    int value = stoi(buffer);
    if (value < minValue || value > maxValue)
        return unexpected(format("Out of range ({}-{})", minValue, maxValue));

    return value;
}

expected<float, string> getFloat(string message, float minValue, float maxValue)
{
    cout << message;
    string buffer;
    getline(cin, buffer);

    if (buffer.empty()) return unexpected("Empty input data");

    string pattern = R"(^-?\d+(\.\d+)?$)";
    if (!regex_match(buffer, regex(pattern)))
        return unexpected("Invalid format data");

    float value = stof(buffer);
    if (value < minValue || value > maxValue)
        return unexpected(format("Out of range ({}-{})", minValue, maxValue));

    return value;
}

void salute(const string &message)
{
    cout << message << "\n";
}

void bye()
{
    cout << "\n Chương trình đang thoát. Nhấn Enter để kết thúc...";
    cin.get();
}