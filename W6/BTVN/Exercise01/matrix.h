#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
using std::ostream;
using std::cout;

class Matrix
{
private:
    int _rows;
    int _cols;
    int **_data;

public:
    Matrix();
    ~Matrix();
    Matrix(int row, int col);

public:
    void setValue(int row, int col, int value);
    int getCol() const;
    int getRow() const;
    friend ostream& operator<<(ostream& os, const Matrix& matrix);              
};

#endif