#include <iostream>
#include <fstream>
using namespace std;

const int max_Size = 31;
struct SSoNguyen
{
    char number[max_Size];
};
SSoNguyen CreateSoNguyen0();
SSoNguyen LoadSoNguyen(istream &);
int SoSanhSoNguyen(const SSoNguyen &, const SSoNguyen &);
SSoNguyen TongSoNguyen(const SSoNguyen &, const SSoNguyen &);
SSoNguyen HieuSoNguyen(const SSoNguyen &, const SSoNguyen &);
void PrintSoNguyen(ostream &, const SSoNguyen &);
int main()
{
    const char pathIn[] = "input.txt";
    ifstream fIn;
    fIn.open(pathIn);
    if (fIn.is_open())
    {
        SSoNguyen snTotal = CreateSoNguyen0();
        while (!fIn.eof())
        {
            SSoNguyen sn = LoadSoNguyen(fIn);
            snTotal = TongSoNguyen(snTotal, sn);
            PrintSoNguyen(cout, sn);
            cout << endl;
        }
        fIn.close();
        PrintSoNguyen(cout, snTotal);
        cout << endl;
    }
    return 0;
}
SSoNguyen CreateSoNguyen0()
{
    SSoNguyen result;
    for (int x = 0; x < 30; x++)
    {
        result.number[x] = '0';
    }
    result.number[30] = '\0';
    return result;
}
SSoNguyen LoadSoNguyen(istream &is)
{
    SSoNguyen result = CreateSoNguyen0();
    char temp;
    for (int i = 0; i < 30; i++)
    {
        is.get(temp);
        if (temp == ',' | temp == '\n')
        {
            result.number[i] = '\0';
            return result;
        }
        result.number[i] = temp;
    }
    return result;
}
int getSize(const SSoNguyen &s1)
{
    int count = 0, i = 0;
    while (s1.number[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}
int SoSanhSoNguyen(const SSoNguyen &s1, const SSoNguyen &s2)
{
    if (getSize(s1) < getSize(s2))
        return -1;
    if (getSize(s1) > getSize(s2))
        return 1;
    for (int i = 0; i < getSize(s1); i++)
    {
        if (s1.number[i] < s2.number[i])
            return -1;
        if (s1.number[i] > s2.number[i])
            return 1;
    }
    return 0;
}
SSoNguyen TongSoNguyen(const SSoNguyen &s1, const SSoNguyen &s2)
{
    SSoNguyen Total = CreateSoNguyen0();
    int compare = SoSanhSoNguyen(s1, s2);
    if (compare == 0)
    {
        if (getSize(s1) < 30)
            Total.number[getSize(s1) + 1] = '\0';
      int remember = 0;
        for (int i = getSize(s1); i >= 0; i--)
        {
            Total.number[i] = s1.number[i] + s2.number[i] + remember;
            if (Total.number[i] > '9')
            {
                remember = 1;
                Total.number[i] -= '0';
            }
        }
        return Total;
    }
    if (compare == -1)
    {
        if (getSize(s2) < 30)
            Total.number[getSize(s2) + 1] = '\0';

        for (int i = getSize(s2); i > getSize(s1); i++)
        {
            Total.number[i] = s2.number[i];
        }
        int remember = 0;
        for (int i = getSize(s1); i >= 0; i--)
        {
            Total.number[i] = s1.number[i] + s2.number[i] + remember;
            if (Total.number[i] > '9')
            {
                remember = 1;
                Total.number[i] -= '0';
            }
        }
        return Total;
    }
    return Total;
}
SSoNguyen HieuSoNguyen(const SSoNguyen &s1, const SSoNguyen &s2)
{
    SSoNguyen result = CreateSoNguyen0();
    return result;
}
void PrintSoNguyen(ostream &os, const SSoNguyen &s1)
{
    for (int i = 0; i < getSize(s1); i++)
    {
        os << s1.number[i];
    }
}