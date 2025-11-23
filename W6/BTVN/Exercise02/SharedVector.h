#ifndef _SHAREDVECTOR_H
#define _SHAREDVECTOR_H

#include <iostream>
using namespace std;

class SharedVector {
private:
    int* _items;
    int _size;
    int _maxSize;
    int* refCount;

public:
    SharedVector(int maxSize = 10);
    SharedVector(const SharedVector& other);
    SharedVector& operator=(const SharedVector& other);
    ~SharedVector();
public:
    friend ostream& operator<<(ostream& os, const SharedVector& vec);
    friend void update1(SharedVector x);
    friend void update2(SharedVector x);
    friend void update3(SharedVector x);
public:
    void add(int value);
    int get(int index) const;
    int size() const;
};

#endif