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
#include "../include/types/vector.hpp"  // Убедитесь, что путь к вашему файлу Vector.h верный

// Тест для конструктора
TEST(VectorTest, DefaultConstructor) {
    Vector<int> vec;
    EXPECT_NO_THROW(vec.print());
}

TEST(VectorTest, SizeConstructor) {
    Vector<int> vec(5);
    EXPECT_EQ(vec.getData().size(), 5);
}

// Тест для арифметических операций
TEST(VectorTest, Addition) {
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 3;

    Vector<int> vec2(3);
    vec2[0] = 4;
    vec2[1] = 5;
    vec2[2] = 6;

    Vector<int> result = vec1 + vec2;

    EXPECT_EQ(result[0], 5);
    EXPECT_EQ(result[1], 7);
    EXPECT_EQ(result[2], 9);
}

TEST(VectorTest, Subtraction) {
    Vector<int> vec1(3);
    vec1[0] = 7;
    vec1[1] = 5;
    vec1[2] = 3;

    Vector<int> vec2(3);
    vec2[0] = 2;
    vec2[1] = 3;
    vec2[2] = 1;

    Vector<int> result = vec1 - vec2;

    EXPECT_EQ(result[0], 5);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 2);
}

TEST(VectorTest, Multiplication) {
    Vector<int> vec1(3);
    vec1[0] = 2;
    vec1[1] = 3;
    vec1[2] = 4;

    Vector<int> vec2(3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 3;

    Vector<int> result = vec1 * vec2;

    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 6);
    EXPECT_EQ(result[2], 12);
}

TEST(VectorTest, Division) {
    Vector<int> vec1(3);
    vec1[0] = 10;
    vec1[1] = 20;
    vec1[2] = 30;

    Vector<int> vec2(3);
    vec2[0] = 2;
    vec2[1] = 5;
    vec2[2] = 10;

    Vector<int> result = vec1 / vec2;

    EXPECT_EQ(result[0], 5);
    EXPECT_EQ(result[1], 4);
    EXPECT_EQ(result[2], 3);
}

// Тесты на исключения
TEST(VectorTest, DivisionByZero) {
    Vector<int> vec1(3);
    vec1[0] = 10;
    vec1[1] = 20;
    vec1[2] = 30;

    Vector<int> vec2(3);
    vec2[0] = 0;  // Деление на 0
    vec2[1] = 5;
    vec2[2] = 10;

    EXPECT_THROW(vec1 / vec2, std::invalid_argument);
}

// Тесты на сравнение
TEST(VectorTest, Equality) {
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 3;

    Vector<int> vec2(3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 3;

    EXPECT_TRUE(vec1 == vec2);
}

TEST(VectorTest, Inequality) {
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 3;

    Vector<int> vec2(3);
    vec2[0] = 4;
    vec2[1] = 5;
    vec2[2] = 6;

    EXPECT_TRUE(vec1 != vec2);
}

// Тест на выход за пределы
TEST(VectorTest, OutOfBoundsAccess) {
    Vector<int> vec(3);
    EXPECT_THROW(vec[5], std::out_of_range);
}

// Тест для префиксных операторов
TEST(VectorTest, PrefixIncrement) {
    Vector<int> vec(3);
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;

    ++vec;

    EXPECT_EQ(vec[0], 2);
    EXPECT_EQ(vec[1], 3);
    EXPECT_EQ(vec[2], 4);
}

// Тест для вывода
TEST(VectorTest, Print) {
    Vector<int> vec(3);
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;

    testing::internal::CaptureStdout();
    vec.print();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(output, "1 2 3 \n");
}

// Тест на ввод
TEST(VectorTest, Input) {
    Vector<int> vec(3);
    std::istringstream input("1 2 3");
    input >> vec;

    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

// Запуск тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
