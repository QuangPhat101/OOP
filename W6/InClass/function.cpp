#include "main.h"

int Fibonacci::generate(int n)
{
    if (n <= 0)
        return 0;
    delete[] this->_elements;
    this->_size = n + 1;
    this->_elements = new int[this->_size];

    this->_elements[0] = 0;
    if (n >= 2)
        this->_elements[1] = 1;

    for (int i = 2; i < this->_size; ++i)
        this->_elements[i] = this->_elements[i - 1] + this->_elements[i - 2];

    return n;
}
Fibonacci::Fibonacci()
{
    this->_size = 0;
    this->_elements = nullptr;
}
Fibonacci::~Fibonacci()
{
    delete[] this->_elements;
}
Fibonacci::Fibonacci(const Fibonacci &other)
{
    this->_size = other._size;
    this->_elements = new int[this->_size];
    for (int i = 0; i <= this->_size; ++i)
        this->_elements[i] = other._elements[i];
}


Fibonacci& Fibonacci::operator=(const Fibonacci &other)
{
    if (this == &other)
        return *this;

    int *newElems = nullptr;
    if (other._size > 0) {
        newElems = new int[other._size];
        for (int i = 0; i <= other._size; ++i)
            newElems[i] = other._elements[i];
    }


    delete[] this->_elements;
    this->_elements = newElems;
    this->_size = other._size;
    return *this;
}

int Fibonacci::getSize() const {
    return this->_size;
}

int Fibonacci::getElement(int index) const {
    if (index < 0 || index >= this->_size || this->_elements == nullptr)
        return 0; 
    return this->_elements[index];
}
ostream &operator<<(std::ostream &os, const Fibonacci &fib)
{
    for (int i = 0; i < fib.getSize(); ++i)
    {
        os << "F[" << i << "] = " << fib.getElement(i) << "\n";
    }
    return os;
}