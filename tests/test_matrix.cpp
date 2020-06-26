#include <iostream>
#include "matrix.hpp"
using namespace std;
void testMatrix(){
    // =============================  setup  ================================
    float f1[9] = {10, 1, 2, 3, 4, 5, 6, 7, 12};
    Matrix<float> *mat1 = new Matrix<float>(f1, 3, 3);
    mat1->print();
    cout << "Determinant of matrix 1 = " << mat1->determinant() << endl;
    cout << "Determinant should be 118\n\n";

    Matrix<float> *mat2 = new Matrix<float> (3,3);
    mat2->set_element(13, 1, 1);
    mat2->print();
    cout << "Determinant of matrix 2 = " << mat2->determinant() << endl;
    cout << "Determinant should be 0\n\n";

    // ==========================  test addition  ===========================
    // TODO: switch to actually test/assert
    Matrix<float> *mat3 = *mat1 + *mat2;
    mat3->print();
    cout << "Determinant of matrix 3 = " << mat3->determinant() << endl;
    cout << "Determinant should be 1522\n\n";


    Matrix<float> *mat4 = mat3->submatrix(1,0);
    mat4->print();
    cout << "Determinant of matrix 4 = " << mat4->determinant() << endl;
    cout << "Determinant should be -2\n\n";
}

int main(int, char**){
    testMatrix();
}