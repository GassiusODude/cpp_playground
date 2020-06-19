#include <exception>
struct MatrixIncompatible : public std::exception{
    const char * what() const throw(){
        return "Incompatible operation for these matrices";
    }
};

template <typename T>
class Matrix{
    public:

        Matrix(int rows, int columns);
        ~Matrix();
        Matrix operator+(Matrix const &m);
        Matrix operator-(Matrix const &m);

    protected:
        T **matrix;
        int rows = 0;
        int columns = 0;

};