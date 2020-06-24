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
        Matrix(int rows, int columns){
            this->rows = rows;
            this->columns = columns;

            // initialize matrix
            this->matrix = new T*[rows];
            for (int row=0; row<rows; row++){
                matrix[row] = new T[columns];
            }
        }

        /**
         * Deconstructor
         */
        ~Matrix();

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

        /**
         * Set an element in the stored matrix.
         * @tparam T is the data stored in the Matrix
         * @param value The value to store at the assigne location on the matrix
         * @param row The row of matrix to set the new value
         * @param col The column of matrix to set the new value
         */
        void setElement(T value, int row, int col);

        // ====================  getters and setters  =======================
        int getRows(){ return rows; }
        int getColumns(){ return columns; }

    protected:
        T **matrix;
    private:
        int rows = 0;
        int columns = 0;

};