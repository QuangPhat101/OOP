#include "matrix.h"

Matrix::Matrix()
{
    this->_rows = 0;
    this->_cols = 0;
    this->_data = nullptr;
}
Matrix::~Matrix()
{
    for (int i = 0; i < this->getRow(); i++)
    {
        delete[] this->_data[i];
    }
    delete[] this->_data;
    cout << "hủy";
}
Matrix::Matrix(int row, int col)
{
    this->_rows = row;
    this->_cols = col;
    this->_data = new int *[row];
    for (int i = 0; i < row; ++i)
        this->_data[i] = new int[col];
}
void Matrix::setValue(int row, int col, int value)
{
    if (row < 0 ||
        row >= this->getRow() ||
        col < 0 ||
        col >= this->getCol())
        return;
    if (this->_data == nullptr ||
        this->getRow() == 0 ||
        this->getCol() == 0)
        return;
    this->_data[row][col] = value;
}
int Matrix::getCol() const
{
    return this->_cols;
}
int Matrix::getRow() const
{
    return this->_rows;
}
ostream &operator<<(ostream &os, const Matrix &matrix)
{
    for (int i = 0; i < matrix.getRow(); i++)
    {
        for (int j = 0; j < matrix.getCol(); j++)
        {
            cout << matrix._data[i][j] << " ";
        }
        cout << "\n";
    }
}