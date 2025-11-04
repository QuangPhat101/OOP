#ifndef MAIN_H
#define MAIN_H

#include <iostream>
using std::cout;
using std::ostream;

class Fibonacci
{
private:
    int _size;
    int *_elements;

public:
    int generate(int n);

public:
    Fibonacci();
    ~Fibonacci();
    Fibonacci(const Fibonacci &other);
    Fibonacci& operator=(const Fibonacci &other);
    friend ostream &operator<<(std::ostream &os, const Fibonacci &fib);

public:
    int getSize() const;
    int getElement(int index) const;
};


#endif // MAIN_H
