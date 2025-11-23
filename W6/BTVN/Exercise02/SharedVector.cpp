#include "SharedVector.h"
// Constructor mặc định
SharedVector::SharedVector(int maxSize)
{
    _maxSize = maxSize;
    _size = 0;
    _items = new int[_maxSize];
    refCount = new int(1);

    // Khởi tạo một số giá trị mẫu
    for (int i = 0; i < 5; i++)
    {
        _items[i] = (i + 1) * 10;
    }
    _size = 5;
}

// Copy constructor - chia sẻ vùng nhớ
SharedVector::SharedVector(const SharedVector &other)
{
    _items = other._items;
    _size = other._size;
    _maxSize = other._maxSize;
    refCount = other.refCount;

    (*refCount)++; // Tăng số lượng tham chiếu
}

// Copy assignment operator
SharedVector &SharedVector::operator=(const SharedVector &other)
{
    if (this != &other)
    {
        // Giảm refCount của đối tượng hiện tại
        (*refCount)--;
        if (*refCount == 0)
        {
            delete[] _items;
            delete refCount;
        }

        // Sao chép con trỏ từ other
        _items = other._items;
        _size = other._size;
        _maxSize = other._maxSize;
        refCount = other.refCount;

        (*refCount)++; // Tăng refCount
    }
    return *this;
}

// Destructor
SharedVector::~SharedVector()
{
    (*refCount)--; // Giảm refCount

    if (*refCount == 0)
    {
        delete[] _items;
        delete refCount;
    }
}

ostream &operator<<(ostream &os, const SharedVector &vec)
{
    os << "SharedVector[items: {";
    for (int i = 0; i < vec._size; i++)
    {
        os << vec._items[i];
        if (i < vec._size - 1)
            os << ", ";
    }
    os << "}, size: " << vec._size;
    os << ", maxSize: " << vec._maxSize;
    os << ", refCount: " << *(vec.refCount);
    os << ", addr: " << vec._items << "]";
    return os;
}

void SharedVector::add(int value)
{
    if (_size < _maxSize)
    {
        _items[_size++] = value;
    }
}

int SharedVector::get(int index) const
{
    if (index >= 0 && index < _size)
    {
        return _items[index];
    }
    return -1;
}

// Lấy kích thước
int SharedVector::size() const
{
    return _size;
}

void update1(SharedVector x)
{
    cout << x << "\n";
    update2(x);
    cout << x << "\n";
}

void update2(SharedVector y)
{
    cout << y << "\n";
    update3(y);
    cout << y << "\n";
}

void update3(SharedVector z)
{
    cout << z << "\n";
}