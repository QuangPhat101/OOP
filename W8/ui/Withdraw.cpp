#include "Withdraw.h"

string formatWithdrawOutput(const int &withdraw)
{
    string result = "";
    int temp = withdraw;
    while (temp / 10 != 0)
    {
        int i = temp % 10;
        result.push_back(i + '0');
        temp /= 10;
    }
    result.push_back(temp + '0');
    std::reverse(result.begin(), result.end());
    for (int i = result.length() - 3; i > 0; i -= 3)
    {
        result.insert(i, ".");
    }
    return result;
}