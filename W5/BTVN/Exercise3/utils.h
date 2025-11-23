#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <vector>
#include <string>
#include <expected>
#include <regex>
#include <format>
#include <functional>

using std::cout, std::cin;
using std::expected, std::unexpected;
using std::format;
using std::function;
using std::regex, std::regex_match;
using std::string;
using std::vector;

expected<int, string> getInt(string message, int minValue, int maxValue);
expected<float, string> getFloat(string message, float minValue, float maxValue);
expected<string, string> getNonEmptyString(string message);

template <typename T>
expected<T, string> getValueRetry(
    string message,
    function<expected<T, string>(string)> getter,
    const int maxAttempts = 3)
{
    int failCount = 0;
    expected<T, string> result;

    do
    {
        result = getter(message);
        if (!result.has_value())
        {
            failCount++;
            cout << "  Lỗi: " << result.error() << "\n";
            if (failCount < maxAttempts)
                cout << format("↻ Nhập lại (còn {} lần)\n\n", maxAttempts - failCount);
        }
    } while (!result.has_value() && failCount < maxAttempts);

    if (!result.has_value())
        return unexpected(" Quá số lần nhập cho phép!");
    return result;
}

template <typename T>
expected<vector<T>, string> getVectorGeneric(
    string message,
    int n,
    function<expected<T, string>(string)> elementGetter,
    int maxAttempts = 3)
{
    vector<T> result;
    for (int i = 0; i < n; ++i)
    {
        string prompt = format("Nhập phần tử thứ {}: ", i + 1);
        auto val = getValueRetry<T>(prompt, elementGetter, maxAttempts);
        if (!val.has_value())
            return unexpected(val.error()); 
        result.push_back(val.value());
    }
    return result;
}
template <typename T>
void executeExerciseGeneric(
    function<void(const vector<T> &)> processor,
    function<expected<T, string>(string)> inputElement)
{
    auto n = getValueRetry<int>(
        "Nhập số lượng phần tử [2-10]: ",
        [](string message)
        { return getInt(message, 2, 10); },
        5);

    if (!n.has_value())
    {
        cout << "\n Không thể tiếp tục: " << n.error() << "\n";
        return;
    }

    auto data = getVectorGeneric<T>("Nhập phần tử", n.value(), inputElement);
    if (!data.has_value())
    {
        cout << "\n Lỗi khi nhập danh sách: " << data.error() << "\n";
        return;
    }

    processor(data.value());
}

void salute(const string &message);
void bye();

#endif // UTILS_H
