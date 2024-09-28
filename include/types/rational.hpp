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

#ifndef RATIONAL_H
#define RATIONAL_H
/**
 * @class Rational
 * @brief A class representing rational numbers with a numerator and denominator.
 *
 * The Rational class provides various arithmetic and bitwise operations for rational numbers.
 * It inherits from the IObject interface and overrides its virtual methods.
 */
template<typename T>
class Rational final : public IObject {
public:
    /**
     * @brief Default constructor that initializes the rational number to 0/1.
     */
    Rational() = default;

    /**
     * @brief Parameterized constructor that initializes the rational number with given numerator and denominator.
     *
     * @param numerator The numerator of the rational number.
     * @param denominator The denominator of the rational number.
     */
    Rational(T numerator, T denominator);

    /**
     * @brief Copy constructor.
     *
     * @param other The Rational object to copy from.
     */
    Rational(const Rational& other);

    /**
     * @brief Move constructor.
     *
     * @param other The Rational object to move from.
     */
    Rational(Rational&& other) noexcept ;

    /**
     * @brief Assignment operator.
     * @param other The Rational object to copy from.
     * @return Reference to the assigned Rational object.
     */
    Rational<T> &operator=(const Rational &other);

    /**
     * @brief Destructor.
     */
    ~Rational() override = default;

    /**
     * @brief Prints the rational number.
     */
    void print() const override;

    /**
     * @brief Pre-increment operator.
     *
     * @return Reference to the incremented Rational object.
     */
    Rational& operator++() override;


    /**
     * @brief Pre-decrement operator.
     *
     * @return Reference to the decremented Rational object.
     */
    Rational& operator--() override;

    /**
     * @brief Modulus operator.
     *
     * @param other The IObject to perform the operation with.
     * @return Reference to the result of the modulus operation.
     */
    Rational& operator%(const IObject& other) const override;

    /**
     * @brief Bitwise AND operator.
     *
     * @param other The IObject to perform the operation with.
     * @return Reference to the result of the bitwise AND operation.
     */
    Rational& operator&(const IObject& other) const override;

    /**
     * @brief Bitwise OR operator.
     *
     * @param other The IObject to perform the operation with.
     * @return Reference to the result of the bitwise OR operation.
     */
    Rational& operator|(const IObject& other) const override;

    /**
     * @brief Bitwise XOR operator.
     *
     * @param other The IObject to perform the operation with.
     * @return Reference to the result of the bitwise XOR operation.
     */
    Rational& operator^(const IObject& other) const override;

    /**
     * @brief Left shift operator.
     *
     * @param other The IObject to perform the operation with.
     * @return Reference to the result of the left shift operation.
     */
    Rational& operator<<(const IObject& other) const override;

    /**
     * @brief Right shift operator.
     *
     * @param other The IObject to perform the operation with.
     * @return Reference to the result of the right shift operation.
     */
    Rational& operator>>(const IObject& other) const override;

    /**
     * @brief Modulus assignment operator.
     *
     * @param other The IObject to perform the operation with.
     * @return Reference to the result of the modulus assignment operation.
     */
    Rational& operator%=(const IObject& other) override;

    /**
     * @brief Bitwise AND assignment operator.
     *
     * @param other The IObject to perform the operation with.
     * @return Reference to the result of the bitwise AND assignment operation.
     */
    Rational& operator&=(const IObject& other) override;

    /**
     * @brief Bitwise OR assignment operator.
     *
     * @param other The IObject to perform the operation with.
     * @return Reference to the result of the bitwise OR assignment operation.
     */
    Rational& operator|=(const IObject& other) override;

    /**
     * @brief Bitwise XOR assignment operator.
     *
     * @param other The IObject to perform the operation with.
     * @return Reference to the result of the bitwise XOR assignment operation.
     */
    Rational& operator^=(const IObject& other) override;

    /**
     * @brief Left shift assignment operator.
     *
     * @param other The IObject to perform the operation with.
     * @return Reference to the result of the left shift assignment operation.
     */
    Rational& operator<<=(const IObject& other) override;

    /**
     * @brief Right shift assignment operator.
     *
     * @param other The IObject to perform the operation with.
     * @return Reference to the result of the right shift assignment operation.
     */
    Rational& operator>>=(const IObject& other) override;

    /**
     * @brief Equality operator.
     *
     * @param other The IObject to compare with.
     * @return True if the objects are equal, false otherwise.
     */
    bool operator==(const IObject& other) const override;

    /**
     * @brief Inequality operator.
     *
     * @param other The IObject to compare with.
     * @return True if the objects are not equal, false otherwise.
     */
    bool operator!=(const IObject& other) const override;

    /**
     * @brief Less than operator.
     *
     * @param other The IObject to compare with.
     * @return True if this object is less than the other, false otherwise.
     */
    bool operator<(const IObject& other) const override;

    /**
     * @brief Less than or equal to operator.
     *
     * @param other The IObject to compare with.
     * @return True if this object is less than or equal to the other, false otherwise.
     */
    bool operator<=(const IObject& other) const override;

    /**
     * @brief Greater than operator.
     *
     * @param other The IObject to compare with.
     * @return True if this object is greater than the other, false otherwise.
     */
    bool operator>(const IObject& other) const override;

    /**
     * @brief Greater than or equal to operator.
     *
     * @param other The IObject to compare with.
     * @return True if this object is greater than or equal to the other, false otherwise.
     */
    bool operator>=(const IObject& other) const override;

    /**
     * @brief Addition operator.
     *
     * @param other The IObject to add.
     * @return Reference to the result of the addition.
     */

    Rational &operator+(const IObject &other) const override;
    /**
     * @brief Subtraction operator.
     *
     * @param other The IObject to subtract.
     * @return The result is a new Rational object.
     */
    Rational<T> &operator=(Rational &&other) noexcept;
    /**
     * @brief Subtraction operator.
     *
     * @param other The IObject to subtract.
     * @return Reference to the result of the subtraction.
     */
    Rational& operator-(const IObject& other) const override;

    /**
     * @brief Multiplication operator.
     *
     * @param other The IObject to multiply.
     * @return Reference to the result of the multiplication.
     */
    Rational& operator*(const IObject& other) const override;

    /**
     * @brief Division operator.
     *
     * @param other The IObject to divide.
     * @return Reference to the result of the division.
     */
    Rational& operator/(const IObject& other) const override;

    /**
     * @brief Addition assignment operator.
     *
     * @param other The IObject to add.
     * @return Reference to the result of the addition assignment.
     */
    Rational& operator+=(const IObject& other) override;

    /**
     * @brief Subtraction assignment operator.
     *
     * @param other The IObject to subtract.
     * @return Reference to the result of the subtraction assignment.
     */
    Rational& operator-=(const IObject& other) override;

    /**
     * @brief Multiplication assignment operator.
     *
     * @param other The IObject to multiply.
     * @return Reference to the result of the multiplication assignment.
     */
    Rational& operator*=(const IObject& other) override;

    /**
     * @brief Division assignment operator.
     *
     * @param other The IObject to divide.
     * @return Reference to the result of the division assignment.
     */
    Rational& operator/=(const IObject& other) override;

    /**
     * @brief Stream insertion operator.
     *
     * @param os The output stream to write to.
     * @param rational The Rational object to write.
     */
    friend std::ostream& operator<<(std::ostream& os, const Rational& rational) {
        os << rational.numerator << '/' << rational.denominator;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Rational& rational) {
        char slash;
        is >> rational.numerator >> slash >> rational.denominator;
        return is;

    }
    /**
     * @brief Stream extraction operator.
     *
     * @param is The input stream to read from.
     * @param r The Rational object to read into.
     */
    friend std::istream& operator>>(std::istream& is, Rational& r) {
        is >> r.numerator >> r.denominator;
        return is;
    }

private:
    /**
     * @brief Represents the numerator part of a fraction.
     *
     * @tparam T The type of the numerator, typically an integer or floating-point type.
     */
    T numerator;
    T denominator;

    /**
     * @brief Reduces the rational number to its simplest form.
     */
    void _reduce();
};
/**
 * @brief Definition of the Vector class template.
 */
#endif //RATIONAL_H
