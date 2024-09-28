/*
 * COPYRIGHT (c) 2024 Massonskyi
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include <gtest/gtest.h>
#include "../include/types/matrix.hpp"  // Убедитесь, что путь к вашему файлу Matrix.h верный

// Тест для конструктора
TEST(MatrixTest, DefaultConstructor) {
    Matrix<int> mat;
    EXPECT_NO_THROW(mat.print());
}

TEST(MatrixTest, SizeConstructor) {
    Matrix<int> mat(2, 3);  // 2 строки, 3 столбца
    EXPECT_EQ(mat.getRows(), 2);
    EXPECT_EQ(mat.getCols(), 3);
}

// Тест для арифметических операций
TEST(MatrixTest, Addition) {
    Matrix<int> mat1(2, 2);
    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 3; mat1[1][1] = 4;

    Matrix<int> mat2(2, 2);
    mat2[0][0] = 5; mat2[0][1] = 6;
    mat2[1][0] = 7; mat2[1][1] = 8;

    Matrix<int> result = mat1 + mat2;

    EXPECT_EQ(result[0][0], 6);
    EXPECT_EQ(result[0][1], 8);
    EXPECT_EQ(result[1][0], 10);
    EXPECT_EQ(result[1][1], 12);
}

TEST(MatrixTest, Subtraction) {
    Matrix<int> mat1(2, 2);
    mat1[0][0] = 5; mat1[0][1] = 6;
    mat1[1][0] = 7; mat1[1][1] = 8;

    Matrix<int> mat2(2, 2);
    mat2[0][0] = 1; mat2[0][1] = 2;
    mat2[1][0] = 3; mat2[1][1] = 4;

    Matrix<int> result = mat1 - mat2;

    EXPECT_EQ(result[0][0], 4);
    EXPECT_EQ(result[0][1], 4);
    EXPECT_EQ(result[1][0], 4);
    EXPECT_EQ(result[1][1], 4);
}

TEST(MatrixTest, Multiplication) {
    Matrix<int> mat1(2, 2);
    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 3; mat1[1][1] = 4;

    Matrix<int> mat2(2, 2);
    mat2[0][0] = 5; mat2[0][1] = 6;
    mat2[1][0] = 7; mat2[1][1] = 8;

    Matrix<int> result = mat1 * mat2;

    EXPECT_EQ(result[0][0], 19);  // (1*5 + 2*7)
    EXPECT_EQ(result[0][1], 22);  // (1*6 + 2*8)
    EXPECT_EQ(result[1][0], 43);  // (3*5 + 4*7)
    EXPECT_EQ(result[1][1], 50);  // (3*6 + 4*8)
}

// Тесты на сравнение
TEST(MatrixTest, Equality) {
    Matrix<int> mat1(2, 2);
    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 3; mat1[1][1] = 4;

    Matrix<int> mat2(2, 2);
    mat2[0][0] = 1; mat2[0][1] = 2;
    mat2[1][0] = 3; mat2[1][1] = 4;

    EXPECT_TRUE(mat1 == mat2);
}

TEST(MatrixTest, Inequality) {
    Matrix<int> mat1(2, 2);
    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 3; mat1[1][1] = 4;

    Matrix<int> mat2(2, 2);
    mat2[0][0] = 5; mat2[0][1] = 6;
    mat2[1][0] = 7; mat2[1][1] = 8;

    EXPECT_TRUE(mat1 != mat2);
}

// Тесты на выход за пределы
TEST(MatrixTest, OutOfBoundsAccess) {
    Matrix<int> mat(2, 2);
    EXPECT_THROW(mat[5][0], std::out_of_range);
}

// Тест для вывода
TEST(MatrixTest, Print) {
    Matrix<int> mat(2, 2);
    mat[0][0] = 1; mat[0][1] = 2;
    mat[1][0] = 3; mat[1][1] = 4;

    testing::internal::CaptureStdout();
    mat.print();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(output, "1 2\n3 4\n");
}

// Тест на ввод
TEST(MatrixTest, Input) {
    Matrix<int> mat(2, 2);
    std::istringstream input("1 2\n3 4");
    input >> mat;

    EXPECT_EQ(mat[0][0], 1);
    EXPECT_EQ(mat[0][1], 2);
    EXPECT_EQ(mat[1][0], 3);
    EXPECT_EQ(mat[1][1], 4);
}

// Запуск тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
