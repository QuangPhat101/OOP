#include <iostream>
#include <vector>
#include <string>
using std::cout, std::ostream;
using std::string;
using std::vector;

// meta programming
template <class T>
using Operator = T (*)(T, T);

template <class T>
T reduce(vector<T> numbers, Operator<T> f, T init)
{
    T result = init;
    for (int i = 0; i < numbers.size(); i++)
    {
        result = f(result, numbers[i]);
    }
    return result;
}

template <class T>
T add(T a, T b)
{
    return a + b;
}

template <class T>
T substract(T a, T b)
{
    return a - b;
}

int main()
{
    // vector<int> a = {1, 2, 3, 4, 5};
    // Operator<int> f = substract<int>;
    // int init = 0;
    // int result = reduce<int>(a, f, init);
    // cout << result;

    vector<string> a = {"Khanh", "ngu"};
    Operator<string> f = add<string>;
    auto init = "";
    string result = reduce<string>(a, f, init);
    cout << result;
}