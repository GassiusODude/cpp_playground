#include "Matrix.hpp"

void testMatrix(){
    // =============================  setup  ================================
    Matrix<float> *mat1 = new Matrix<float>(3,3);
    mat1->setElement(10, 0, 0);
    mat1->setElement(7, 2, 2);
    mat1->print();

    Matrix<float> *mat2 = new Matrix<float> (3,3);
    mat2->setElement(13, 1, 1);
    mat2->print();

    // ==========================  test addition  ===========================
    Matrix<float> *mat3 = *mat1 + *mat2;
    mat3->print();

}

int main(int, char**){
    testMatrix();
}