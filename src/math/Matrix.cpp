#include "Matrix.hpp"

using namespace std;

//template <typename T>

template <typename T>
Matrix<T>::~Matrix(){
    delete [] matrix;
}

template <typename T>
Matrix<T>* Matrix<T>::operator+(Matrix<T> const &mat){
    // --------------------  error checking  --------------------------------
    if (this->rows != mat.rows || this->columns != mat.columns)
        throw MatrixIncompatible();

    // ---------------  create output matrix and add  -----------------------
    Matrix<T> *out = new Matrix(this->rows, this-> columns);
    for (int row=0; row<this->rows; row++)
        for (int col=0; col<this->columns; col++){
            out->matrix[row][col] += mat.matrix[row][col];
        }
    return out;
}

template <typename T>
Matrix<T>* Matrix<T>::operator-(Matrix<T> const &mat){
    // --------------------  error checking  --------------------------------
    if (this->rows != mat.rows || this->columns != mat.columns)
        throw MatrixIncompatible();

    // ---------------  create output matrix and add  -----------------------
    Matrix<T> *out = new Matrix(this->rows, this-> columns);
    for (int row=0; row<this->rows; row++)
        for (int col=0; col<this->columns; col++){
            out->matrix[row][col] -= mat.matrix[row][col];
        }
    return out;
}

template <typename T>
void Matrix<T>::setElement(T value, int row, int col){
    if (row < 0 || row >= rows)
        std::cerr << "row is out of bounds of the Matrix\n";
    else if (col < 0 || col >= columns)
        std::cerr << "col is out of bounds of the Matrix\n";
    this->matrix[row][col] = value;
}

template <typename T>
void Matrix<T>::print(){
    cout << "Matrix/n";
    cout << "\tRow = " << this->rows << endl;
    cout << "\tColumns = " << this->rows << endl;

    for (int row=0; row<this->rows; row++){
        for (int col=0; col<this->columns; col++){
            cout << this->matrix[row][col] << ", ";
        }
        cout << endl;
    }
}
/*
template <typename T>
int Matrix<T>::getRows(){ return this->rows; }
template <typename T>
int Matrix<T>::getColumns(){ return this->columns; }
*/

template class Matrix<float>;
//template void Matrix<float>::print();
//template void Matrix<float>::setElement(float, int, int);