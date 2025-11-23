#include <iostream>
#include <string>
using std::cout, std::cin;
using std::ostream;
using std::string;

template <class T>
class Vector
{
private:
    T *start;     // con tro toi mang tinh luu vector
    int size;     // so luong phan tu hien tai
    int capacity; // suc chua

    void resize()
    {
        if (capacity == 0)
            capacity = 1;
        else
            capacity *= 2;
        T *newData = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            newData[i] = start[i];
        }
        delete[] start;
        start = newData;
    }

public:
    Vector() : start(NULL), size(0), capacity(0) {};
    Vector(int size)
    {
        T *data = new T[size];
        start = data;
        capacity = size;
        this->size = 0;
    }

    Vector(int size, T defaultValue)
    {
        T *data = new T[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = defaultValue;
        }
        start = data;
        this->size = size;
        capacity = size;
    }

    void push(const T value)
    {
        if (size == capacity)
        {
            resize();
        }
        start[size] = value;
        size++;
    }
    int getCapacity() const
    {
        return this->capacity;
    }
    int getSize() const
    {
        return this->size;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << start[i] << "\n";
        }
        cout << '\n';
    }
    T operator[](){
        if (index < 0 || 
    }
};
class SinhVien
{
public:
    string ID;
    string Name;
    float GPA;

public:
};

ostream &operator<<(ostream &out, const SinhVien &sv)
{
    out << sv.ID << " - " << sv.Name << " - " << sv.GPA;
    return out;
}

int main()
{
    // test case 1;
    // int n;
    // cin >> n;
    // Vector<int> vec(n);
    // for (int i = 0; i < n; i++)
    // {
    //     int temp;
    //     cin >> temp;
    //     vec.push(temp);
    // }
    // vec.print();

    // test case 2:
    // int n;
    // cin >> n;
    // Vector<std::string> stringVec(n);
    // std::cin.ignore();
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Nhap string thu " << i + 1 << ": ";
    //     std::string str;
    //     std::getline(std::cin, str);
    //     stringVec.push(str);
    // }
    // stringVec.print();

    // Test case 3:
    int n;
    cin >> n;
    Vector<SinhVien> svVec(n);
    for (int i = 0; i < n; i++)
    {
        SinhVien sv;
        cout << "Nhap sinh vien thu " << i + 1 << ": \n";
        cout << "   Hay nhap ID: ";
        cin >> sv.ID;
        cout << "   Hay nhap Ho va Ten: ";
        std::cin.ignore();
        std::getline(std::cin, sv.Name);
        cout << "   Hay nhap GPA: ";
        cin >> sv.GPA;

        svVec.push(sv);
    }
    svVec.print();
}
