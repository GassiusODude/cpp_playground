#include <iostream>
#include "matrix.hpp"
#include "gtest/gtest.h"
namespace {
    class MatrixTest : public testing::Test{
        public:
            Matrix<float> *mat1;
            Matrix<float> *mat2;
            Matrix<float> *mat3;
            Matrix<float> *mat4;
            Matrix<float> *mat5;

        protected:
            void SetUp() override{
                float f1[9] = {10, 1, 2, 3, 4, 5, 6, 7, 12};
                mat1 = new Matrix<float>(f1, 3, 3);
                mat2 = new Matrix<float>(3,3);
                mat2->set_element(13, 1, 1);
                mat3 = *mat1 + *mat2;
                mat4 = mat3->submatrix(1,0);
            }

            void TearDown() override{
                delete mat1;
                delete mat2;
                delete mat3;
                delete mat4;


            }
    };
    TEST_F(MatrixTest, Add){
        /*
        Matrix<float> *mat3a = *mat1 + *mat2;
        EXPECT_EQ(10, mat3->matrix_[0][0]);
        EXPECT_EQ(1, mat3->matrix_[0][1]);
        EXPECT_EQ(2, mat3->matrix_[0][2]);
        EXPECT_EQ(3, mat3->matrix_[1][0]);
        EXPECT_EQ(17, mat3->matrix_[1][1]);
        EXPECT_EQ(5, mat3->matrix_[1][2]);
        EXPECT_EQ(6, mat3->matrix_[2][0]);
        EXPECT_EQ(7, mat3->matrix_[2][1]);
        EXPECT_EQ(12, mat3->matrix_[2][2]);
        delete mat3a;*/
    }
    TEST_F(MatrixTest, Determinant){
        EXPECT_EQ(118, mat1->determinant());
        EXPECT_EQ(0, mat2->determinant());
        EXPECT_EQ(1522, mat3->determinant());
        EXPECT_EQ(-2, mat4->determinant());
    }
}
