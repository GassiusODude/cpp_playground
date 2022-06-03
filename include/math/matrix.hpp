/**
 * @brief Matrix object
 * @details Matrix object and associated functions
 * @author Keith Chow
 * @version 0.1
 * @date 2020
 */
#include <iostream>
#include <exception>
struct MatrixIncompatible : public std::exception{
    const char * what() const throw(){
        return "Incompatible operation for these matrices";
    }
};

template <typename T>
class Matrix {
    public:
        /**
         * Constructor
         *
         * @param rows Number of rows
         * @param columns Number of columns per row.
         */
        Matrix(int rows, int columns);

        /**
         * Constructor
         *
         * @param newMat The multi-dimension array to initialize the matrix
         * @param rows Number of rows
         * @param columns Number of columns per row.
         */
        Matrix(T *newMat, int rows, int columns);

        /**
         * Deconstructor
         */
        ~Matrix();

        /** Print information about the matrix */
        void print();

        /**
         * Add the current Matrix with another Matrix
         * @tparam T is the type of data stored in the Matrix
         * @param mat The new Matrix
         * @return New matrix, sum of this Matrix and the Matrix.
         */
        Matrix* operator+(Matrix const &m);

        /**
         * Subtract the current Matrix by supplied Matrix
         * @tparam T is the type of data stored in the Matrix
         * @param mat The Matrix to subtrac the current matrix by
         * @return New matrix, subtraction of this Matrix and the supplied Matrix.
         */
        Matrix* operator-(Matrix const &m);

        Matrix<T>* submatrix(int row, int col);

        T getIndex(int row, int col) { return matrix_[row][col]; }

        T determinant();

        T determinant(Matrix *m);

        /**
         * Set an element in the stored matrix.
         * @tparam T is the data stored in the Matrix
         * @param value The value to store at the assigne location on the matrix
         * @param row The row of matrix to set the new value
         * @param col The column of matrix to set the new value
         */
        void set_element(T value, int row, int col);

        // ====================  getters and setters  =======================
        int getRows(){ return rows_; }
        int getColumns(){ return columns_; }

    protected:
        T **matrix_;
    private:
        int rows_ = 0;
        int columns_ = 0;

};