#include <iostream>
using std::cout;
using std::ostream;

class SharedVector
{
private:
    int *_items;
    int _size;
    int _maxSize;
    int *refCount;

public:
    friend ostream &operator<<(ostream &os, const SharedVector &vec);
};

void update1(SharedVector x)
{
    cout << x << "\n"; // In ra tất cả thông tin của vector, chú ý refCount để xem
    update2(x);
    cout << x << "\n"; // In ra tất cả thông tin của vector, chú ý refCount để xem
}
void update2(SharedVector y)
{
    cout << y << "\n"; // In ra tất cả thông tin của vector, chú ý refCount để xem
    update3(y);
    cout << y << "\n"; // In ra tất cả thông tin của vector, chú ý refCount để xem
}
void update3(SharedVector z)
{
    cout << z << "\n"; // In ra tất cả thông tin của vector, chú ý refCount để xem
}

void main()
{
    SharedVector a;
    update1(a);
}
