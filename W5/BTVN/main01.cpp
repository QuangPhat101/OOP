#include <iostream>
#include <vector>
#include <string>
#include <expected>
#include <regex>
#include <format>
#include "Exercise3/utils.h"

using std::cout, std::cin, std::ostream;
using std::expected, std::unexpected;
using std::format;
using std::regex, std::regex_match;
using std::string, std::vector;

void executeExercise01();

int main()
{
    salute("Bài tập 01: Chương trình tính tổng các số chẵn và in tổng dãy số ra màn hình\n");
    executeExercise01();
    bye();
    return 0;
}

void executeExercise01()
{
    executeExerciseGeneric<int>(
    [](const vector<int>& numbers) {
        int sum = 0;
        for (auto x : numbers)
            if (x % 2 == 0)
                sum += x;
        cout << format("Tổng các số chẵn là: {}\n", sum);
    },
    [](string message) { 
        return getInt(message + " [10-100]: ", 10, 100);
    }
);

}