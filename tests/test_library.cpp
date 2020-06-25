#ifdef NDEBUG
#define assert(condition) ((void)0)
#else
#define assert(condition) /*implementation defined*/
#endif

#include "Matrix.hpp"

void testMatrix(){
    // =============================  setup  ================================
    float f1[9] = {10, 0, 0, 0, 0, 0, 0, 0, 7};
    Matrix<float> *mat1 = new Matrix<float>(f1, 3, 3);
    mat1->print();

    Matrix<float> *mat2 = new Matrix<float> (3,3);
    mat2->setElement(13, 1, 1);
    mat2->print();

    // ==========================  test addition  ===========================
    // TODO: switch to actually test/assert
    Matrix<float> *mat3 = *mat1 + *mat2;
    mat3->print();
}

int main(int, char**){
    testMatrix();
}