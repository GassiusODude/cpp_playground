#include "Matrix.hpp"

using namespace std;
template <typename T>
Matrix<T>::Matrix(int rows, int columns){
    this->rows = rows;
    this->columns = columns;
    this->matrix = new T[rows];
    for (int row=0; row<rows; row++)
        this->matrix[row] = new T[columns];
}

template <typename T>
Matrix<T>::~Matrix(){
    delete [] matrix;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> const &mat){
    // --------------------  error checking  --------------------------------
    if (this->rows != mat.getRows() || this->columns != mat.getColumns())
        throw MatrixIncompatible();

    // ---------------  create output matrix and add  -----------------------
    Matrix<T> out = new Matrix(this->rows, this-> columns);
    for (int row=0; row<this->rows; row++)
        for (int col=0; col<this.columns; col++){
            out[row][col] += mat[row][col];
        }
    return out;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> const &mat){
    // --------------------  error checking  --------------------------------
    if (this->rows != mat.getRows() || this->columns != mat.getColumns())
        throw MatrixIncompatible();

    // ---------------  create output matrix and add  -----------------------
    Matrix<T> out = new Matrix(this->rows, this-> columns);
    for (int row=0; row<this->rows; row++)
        for (int col=0; col<this.columns; col++){
            out[row][col] -= mat[row][col];
        }
    return out;
}
