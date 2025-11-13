#include "matrix.h"

Matrix::Matrix()
{
    this->_rows = 0;
    this->_cols = 0;
    this->_data = nullptr;
}

Matrix::~Matrix()
{
    if (this->_data == nullptr)
        return;
    for (int i = 0; i < this->getRow(); i++)
    {
        delete[] this->_data[i];
    }
    delete[] this->_data;
}

Matrix::Matrix(int row, int col)
{
    this->_rows = row;
    this->_cols = col;
    this->_data = new int *[row];
    for (int i = 0; i < row; ++i)
        this->_data[i] = new int[col];
}
Matrix::Matrix(const Matrix &other)
{
    this->_cols = other.getCol();
    this->_rows = other.getRow();
    this->_data = new int *[this->getRow()];
    for (int i = 0; i < this->getRow(); i++)
    {
        this->_data[i] = new int[this->getCol()];
        for (int j = 0; j < this->getCol(); j++)
        {
            this->_data[i][j] = other._data[i][j];
        }
    }
}
Matrix &Matrix::operator=(const Matrix &other)
{
    if (this == &other)
        return *this;
    for (int i = 0; i < this->getRow(); i++)
    {
        delete[] this->_data[i];
    }
    delete[] this->_data;
    this->_cols = other.getCol();
    this->_rows = other.getRow();
    this->_data = new int *[this->getRow()];
    for (int i = 0; i < this->getRow(); i++)
    {
        this->_data[i] = new int[this->getCol()];
        for (int j = 0; j < this->getCol(); j++)
        {
            this->_data[i][j] = other._data[i][j];
        }
    }
    return *this;
}
void Matrix::setValue(int row, int col, int value)
{
    if (this->_data == nullptr)
    {
        return;
    }
    if (row < 0 ||
        row >= this->getRow() ||
        col < 0 ||
        col >= this->getCol())
    {
        return;
    }
    if (this->_data == nullptr ||
        this->getRow() == 0 ||
        this->getCol() == 0)
    {
        return;
    }
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
            os << matrix._data[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}