#include "Matrix.hpp"

using namespace std;


template <typename T>
Matrix<T>::Matrix(int rows, int columns){
    this->rows = rows;
    this->columns = columns;

    // initialize matrix
    this->matrix = new T*[rows];
    for (int row=0; row<rows; row++){
        matrix[row] = new T[columns];
    }
}

template <typename T>
Matrix<T>::Matrix(T *newMat, int rows, int columns){
    this->rows = rows;
    this->columns = columns;
    // initialize matrix
    this->matrix = new T*[rows];
    for (int row=0; row<rows; row++){
        matrix[row] = new T[columns];
    }

    // assign values
    for (int ind0=0; ind0<rows; ind0++)
        for(int ind1=0; ind1<columns; ind1++)
            matrix[ind0][ind1] = newMat[ind0 * columns + ind1];
};

template <typename T>
Matrix<T>::~Matrix(){
    delete [] matrix;
};

template <typename T>
Matrix<T>* Matrix<T>::operator+(Matrix<T> const &mat){
    // --------------------  error checking  --------------------------------
    if (this->rows != mat.rows || this->columns != mat.columns)
        throw MatrixIncompatible();

    // ---------------  create output matrix and add  -----------------------
    Matrix<T> *out = new Matrix(this->rows, this-> columns);
    for (int row=0; row<this->rows; row++)
        for (int col=0; col<this->columns; col++){
            out->matrix[row][col] = this->matrix[row][col]
                + mat.matrix[row][col];
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
            out->matrix[row][col] = this->matrix[row][col]
                - mat.matrix[row][col];
        }
    return out;
};

template <typename T>
void Matrix<T>::setElement(T value, int row, int col){
    if (row < 0 || row >= rows)
        std::cerr << "row is out of bounds of the Matrix\n";
    else if (col < 0 || col >= columns)
        std::cerr << "col is out of bounds of the Matrix\n";
    this->matrix[row][col] = value;
};

template <class T>
void Matrix<T>::print(){
    cout << "Matrix," << "\tRow = " << this->rows;
    cout << "\tColumns = " << this->rows << endl;

    for (int row=0; row<this->rows; row++){
        for (int col=0; col<this->columns; col++){
            cout << this->matrix[row][col] << ", ";
        }
        cout << endl;
    }
};

// explicit instantiation of class templates
template class Matrix<float>;
template class Matrix<int>;
