#include <iostream>
#include <vector>
#include <string>
using std::cout, std::ostream;
using std::string;
using std::vector;

class Integer
{
public:
    typedef int (*Operator)(int, int);

public:
    static int add(int a, int b);
    static int multiply(int a, int b);
    static int min(int a, int b);
    static int max(int a, int b);

    static int reduce(vector<int> numbers, Operator f, int init);
};

int main()
{
    Integer::Operator f = Integer::add;
    int init = 0;
    vector<int> numbers = {1, 2, 3, 4, 5};
    int result = Integer::reduce(numbers, f, init);
    cout << "Result: " << result;
    return 0;
}

int Integer::add(int a, int b)
{
    return a + b;
}

int Integer::multiply(int a, int b)
{
    return a * b;
}
int Integer::max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int Integer::min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int Integer::reduce(vector<int> numbers, Integer::Operator f, int init)
{
    int result = init;
    for (int i = 0; i < numbers.size(); i++)
    {
        result = f(result, numbers[i]);
    }
    return result;
}