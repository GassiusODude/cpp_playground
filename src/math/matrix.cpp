#include "matrix.hpp"

using namespace std;


template <typename T>
Matrix<T>::Matrix(int rows, int columns){
    rows_ = rows;
    columns_ = columns;

    // initialize matrix
    this->matrix_ = new T*[rows];
    for (int row=0; row<rows_; row++){
        matrix_[row] = new T[columns];
    }
}

template <typename T>
Matrix<T>::Matrix(T *newMat, int rows, int columns){
    rows_ = rows;
    columns_ = columns;
    // initialize matrix
    matrix_ = new T*[rows];
    for (int row=0; row<rows; row++){
        matrix_[row] = new T[columns];
    }

    // assign values
    for (int ind0=0; ind0<rows; ind0++)
        for(int ind1=0; ind1<columns; ind1++)
            matrix_[ind0][ind1] = newMat[ind0 * columns + ind1];
};

template <typename T>
Matrix<T>::~Matrix(){
    delete [] matrix_;
};

template <typename T>
Matrix<T>* Matrix<T>::operator+(Matrix<T> const &mat){
    // --------------------  error checking  --------------------------------
    if (this->rows_ != mat.rows_ || this->columns_ != mat.columns_)
        throw MatrixIncompatible();

    // ---------------  create output matrix and add  -----------------------
    Matrix<T> *out = new Matrix(rows_, columns_);
    for (int row=0; row<this->rows_; row++)
        for (int col=0; col<this->columns_; col++){
            out->matrix_[row][col] = this->matrix_[row][col]
                + mat.matrix_[row][col];
        }
    return out;
}

template <typename T>
Matrix<T>* Matrix<T>::operator-(Matrix<T> const &mat){
    // --------------------  error checking  --------------------------------
    if (this->rows_ != mat.rows_ || this->columns_ != mat.columns_)
        throw MatrixIncompatible();

    // ---------------  create output matrix and add  -----------------------
    Matrix<T> *out = new Matrix(this->rows_, this->columns_);
    for (int row=0; row<this->rows_; row++)
        for (int col=0; col<this->columns_; col++){
            out->matrix_[row][col] = this->matrix_[row][col]
                - mat.matrix_[row][col];
        }
    return out;
};

template <typename T>
void Matrix<T>::set_element(T value, int row, int col){
    if (row < 0 || row >= rows_)
        std::cerr << "row is out of bounds of the Matrix\n";
    else if (col < 0 || col >= columns_)
        std::cerr << "col is out of bounds of the Matrix\n";
    this->matrix_[row][col] = value;
};

template <typename T>
void Matrix<T>::print(){
    cout << "Matrix," << "\tRow = " << this->rows_;
    cout << "\tColumns = " << this->rows_ << endl;

    for (int row=0; row<this->rows_; row++){
        for (int col=0; col<this->columns_; col++){
            cout << this->matrix_[row][col] << ", ";
        }
        cout << endl;
    }
};

template <typename T>
Matrix<T>* Matrix<T>::submatrix(int row, int col){
    Matrix<T>* output;
    if (this->rows_ <= 1 || this->columns_ <= 1){
        output = new Matrix<T>(0, 0);
    }
    else{
        output = new Matrix<T>(this->rows_-1, this->columns_-1);
        int outRow=0, outCol=0;
        int indRow, indCol;
        for (indRow=0; indRow < this->rows_; indRow++){
            if (indRow == row)
                continue;

            // reset the output column
            outCol = 0;
            for (indCol=0; indCol < this->columns_; indCol++){
                if (indCol != col)
                    output->matrix_[outRow][outCol++] = matrix_[indRow][indCol];
            }
            outRow++;
        }
    }
    return output;
};

template <typename T>
T Matrix<T>::determinant(){
    return determinant(this);
};

template <typename T>
T Matrix<T>::determinant(Matrix<T> *m){
    // -------------------  handle exit conditions  -------------------------
    if (m->getRows() == 0 || m->getColumns() == 0)
        return 0;
    if (m->getRows() == 2 && m->getColumns() == 2)
        return m->matrix_[0][0] * m->matrix_[1][1]
            - m->matrix_[0][1] * m->matrix_[1][0];

    // -------------------  get determinants of submatrics  -----------------
    T sum = 0;
    int mult = 1;
    for (int col = 0; col < m->getColumns(); col++){
        sum += m->matrix_[0][col] * mult * determinant(submatrix(0, col));
        mult *= -1;
    }
    return sum;
};

// explicit instantiation of class templates
template class Matrix<float>;
template class Matrix<int>;
