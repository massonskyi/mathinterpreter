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
#include "../include/types/rational.hpp" // Предполагается, что Rational объявлен здесь

class RationalTests : public ::testing::Test {
protected:
    void SetUp() override {
        // Настройка, если требуется
    }

    void TearDown() override {
        // Очистка, если требуется
    }
};

TEST_F(RationalTests, DefaultConstructor) {
    Rational<int> r; // Создание рационального числа по умолчанию
    EXPECT_EQ(r.getNumerator(), 0);
    EXPECT_EQ(r.getDenominator(), 1);
}

TEST_F(RationalTests, ParameterizedConstructor) {
    Rational r(3, 4); // Создание рационального числа 3/4
    EXPECT_EQ(r.getNumerator(), 3);
    EXPECT_EQ(r.getDenominator(), 4);
}

TEST_F(RationalTests, NegativeNumerator) {
    Rational r(-3, 4);
    EXPECT_EQ(r.getNumerator(), -3);
    EXPECT_EQ(r.getDenominator(), 4);
}

TEST_F(RationalTests, NegativeDenominator) {
    Rational r(3, -4);
    EXPECT_EQ(r.getNumerator(), -3);
    EXPECT_EQ(r.getDenominator(), 4);
}

TEST_F(RationalTests, Addition) {
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational result = r1 + r2; // 1/2 + 1/3 = 5/6
    EXPECT_EQ(result.getNumerator(), 5);
    EXPECT_EQ(result.getDenominator(), 6);
}

TEST_F(RationalTests, Subtraction) {
    Rational r1(3, 4);
    Rational r2(1, 4);
    Rational result = r1 - r2; // 3/4 - 1/4 = 2/4 = 1/2
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 2);
}

TEST_F(RationalTests, Multiplication) {
    Rational r1(1, 2);
    Rational r2(2, 3);
    Rational result = r1 * r2; // 1/2 * 2/3 = 2/6 = 1/3
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 3);
}

TEST_F(RationalTests, Division) {
    Rational r1(1, 2);
    Rational r2(2, 3);
    Rational result = r1 / r2; // 1/2 ÷ 2/3 = 1/2 * 3/2 = 3/4
    EXPECT_EQ(result.getNumerator(), 3);
    EXPECT_EQ(result.getDenominator(), 4);
}

TEST_F(RationalTests, Simplification) {
    Rational r(4, 8); // 4/8 должно упроститься до 1/2
    EXPECT_EQ(r.getNumerator(), 1);
    EXPECT_EQ(r.getDenominator(), 2);
}

TEST_F(RationalTests, Comparison) {
    Rational r1(1, 2);
    Rational r2(2, 4);
    EXPECT_TRUE(r1 == r2); // 1/2 равно 2/4

    Rational r3(1, 3);
    EXPECT_TRUE(r1 > r3); // 1/2 больше 1/3
    EXPECT_TRUE(r1 < Rational(3, 4)); // 1/2 меньше 3/4
}

TEST_F(RationalTests, OutputStream) {
    Rational r(1, 2);
    std::ostringstream os;
    os << r;
    EXPECT_EQ(os.str(), "1/2");
}

TEST_F(RationalTests, InputStream) {
    Rational<int> r;
    std::istringstream is("3/4");
    is >> r;
    EXPECT_EQ(r.getNumerator(), 3);
    EXPECT_EQ(r.getDenominator(), 4);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
