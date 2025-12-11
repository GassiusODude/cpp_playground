#include "matrix.hpp"
#include <iostream>

using namespace std;

template <typename T>
Matrix<T>::Matrix(int rows, int columns)
    : rows_(rows), columns_(columns)
{
    if (rows_ <= 0 || columns_ <= 0) {
        matrix_ = nullptr;
        return;
    }

    // allocate rows and zero-initialize each row
    matrix_ = new T*[rows_];
    for (int r = 0; r < rows_; ++r) {
        matrix_[r] = new T[columns_](); // value-initialize (zeros for builtins)
    }
}

template <typename T>
Matrix<T>::Matrix(T *newMat, int rows, int columns)
    : rows_(rows), columns_(columns)
{
    if (rows_ <= 0 || columns_ <= 0) {
        matrix_ = nullptr;
        return;
    }

    matrix_ = new T*[rows_];
    for (int r = 0; r < rows_; ++r) {
        matrix_[r] = new T[columns_]();
    }

    // copy values from provided array (row-major)
    for (int r = 0; r < rows_; ++r) {
        for (int c = 0; c < columns_; ++c) {
            matrix_[r][c] = newMat[r * columns_ + c];
        }
    }
}

template <typename T>
Matrix<T>::~Matrix()
{
    if (!matrix_) return;

    for (int r = 0; r < rows_; ++r) {
        delete[] matrix_[r];
    }
    delete[] matrix_;
    matrix_ = nullptr;
}

template <typename T>
Matrix<T>* Matrix<T>::operator+(Matrix<T> const &mat)
{
    // --------------------  error checking  --------------------------------
    if (this->rows_ != mat.rows_ || this->columns_ != mat.columns_)
        throw MatrixIncompatible();

    // ---------------  create output matrix and add  -----------------------
    Matrix<T> *out = new Matrix<T>(this->rows_, this->columns_);
    for (int row = 0; row < this->rows_; ++row)
        for (int col = 0; col < this->columns_; ++col) {
            out->matrix_[row][col] = this->matrix_[row][col]
                + mat.matrix_[row][col];
        }
    return out;
}

template <typename T>
Matrix<T>* Matrix<T>::operator-(Matrix<T> const &mat)
{
    if (this->rows_ != mat.rows_ || this->columns_ != mat.columns_)
        throw MatrixIncompatible();

    Matrix<T> *out = new Matrix<T>(this->rows_, this->columns_);
    for (int row = 0; row < this->rows_; ++row)
        for (int col = 0; col < this->columns_; ++col) {
            out->matrix_[row][col] = this->matrix_[row][col]
                - mat.matrix_[row][col];
        }
    return out;
}

template <typename T>
void Matrix<T>::set_element(T value, int row, int col)
{
    if (row < 0 || row >= rows_) {
        std::cerr << "row is out of bounds of the Matrix\n";
        return;
    }
    if (col < 0 || col >= columns_) {
        std::cerr << "col is out of bounds of the Matrix\n";
        return;
    }
    this->matrix_[row][col] = value;
}

template <typename T>
void Matrix<T>::print()
{
    cout << "Matrix," << "\tRow = " << this->rows_;
    cout << "\tColumns = " << this->columns_ << endl;

    if (!matrix_) {
        cout << "<empty matrix>" << endl;
        return;
    }

    for (int row = 0; row < this->rows_; ++row) {
        for (int col = 0; col < this->columns_; ++col) {
            cout << this->matrix_[row][col] << ", ";
        }
        cout << endl;
    }
}

template <typename T>
Matrix<T>* Matrix<T>::submatrix(int row, int col)
{
    if (this->rows_ <= 0 || this->columns_ <= 0)
        return new Matrix<T>(0, 0);

    if (this->rows_ == 1 && this->columns_ == 1)
        return new Matrix<T>(0, 0);

    Matrix<T>* output = new Matrix<T>(this->rows_-1, this->columns_-1);
    int outRow = 0;
    for (int r = 0; r < this->rows_; ++r) {
        if (r == row) continue;
        int outCol = 0;
        for (int c = 0; c < this->columns_; ++c) {
            if (c == col) continue;
            output->matrix_[outRow][outCol] = this->matrix_[r][c];
            ++outCol;
        }
        ++outRow;
    }
    return output;
}

template <typename T>
T Matrix<T>::determinant()
{
    return determinant(this);
}

template <typename T>
T Matrix<T>::determinant(Matrix<T> *m)
{
    // safety checks
    if (!m || !m->matrix_ || m->getRows() <= 0 || m->getColumns() <= 0)
        return 0;

    int R = m->getRows();
    int C = m->getColumns();

    // base cases
    if (R == 1 && C == 1)
        return m->matrix_[0][0];

    if (R == 2 && C == 2)
        return m->matrix_[0][0] * m->matrix_[1][1]
            - m->matrix_[0][1] * m->matrix_[1][0];

    // recursive expansion by first row
    T sum = static_cast<T>(0);
    int sign = 1;
    for (int c = 0; c < C; ++c) {
        // create minor of m for (0,c)
        Matrix<T>* minor = m->submatrix(0, c); // submatrix of m
        T cofactor = m->matrix_[0][c] * static_cast<T>(sign) * determinant(minor);
        sum += cofactor;
        delete minor; // avoid memory leak
        sign = -sign;
    }
    return sum;
}

// explicit instantiation of class templates
template class Matrix<float>;
template class Matrix<int>;
