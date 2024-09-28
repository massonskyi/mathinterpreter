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

#ifndef MATRIX_H
#define MATRIX_H
#include <istream>
#include <vector>

#include "iobject.h"
#include "vector.hpp"

/**
 * @brief Concept for incrementable types.
 *
 * This concept requires that the type T supports the prefix increment and decrement operators.
 *
 * @tparam T The type to check.
 */
template<typename T>
concept Incrementable = requires(T a) {
 { ++a } -> std::same_as<T&>;
 { --a } -> std::same_as<T&>;
};

/**
 * @brief Template class Matrix representing a matrix.
 *
 * @tparam T Type of the elements in the matrix.
 */
template<typename T>
class Matrix<T> final : public IObject {
public:
    /**
     * @brief Default constructor.
     */
    Matrix() = default;

    /**
     * @brief Constructor that takes a vector of vectors.
     *
     * @param vec Vector of vectors representing the rows of the matrix.
     */
    explicit Matrix(const Vector<T>& vec);

    /**
     * @brief Move constructor.
     *
     * @param other Another Matrix object to move.
     */
    Matrix(Matrix&& other)  noexcept {}

    /**
     * @brief Destructor.
     */
    ~Matrix() override = default;

    /**
     * @brief Prints the contents of the matrix.
     */
    void print() const override;

    /**
     * @brief Equality comparison operator.
     *
     * @param other Another object to compare with.
     * @return true if the objects are equal, otherwise false.
     */
    bool operator==(const IObject& other) const override;

    /**
     * @brief Inequality comparison operator.
     *
     * @param other Another object to compare with.
     * @return true if the objects are not equal, otherwise false.
     */
    bool operator!=(const IObject& other) const override;

    /**
     * @brief Less than comparison operator.
     *
     * @param other Another object to compare with.
     * @return true if this object is less than the other, otherwise false.
     */
    bool operator<(const IObject& other) const override;

    /**
     * @brief Less than or equal to comparison operator.
     *
     * @param other Another object to compare with.
     * @return true if this object is less than or equal to the other, otherwise false.
     */
    bool operator<=(const IObject& other) const override;

    /**
     * @brief Greater than comparison operator.
     *
     * @param other Another object to compare with.
     * @return true if this object is greater than the other, otherwise false.
     */
    bool operator>(const IObject& other) const override;

    /**
     * @brief Greater than or equal to comparison operator.
     *
     * @param other Another object to compare with.
     * @return true if this object is greater than or equal to the other, otherwise false.
     */
    bool operator>=(const IObject& other) const override;

    /**
     * @brief Addition operator.
     *
     * @param other Another object to add.
     * @return Resulting Matrix after addition.
     */
    Matrix& operator+(const IObject& other) const override;

    /**
     * @brief Subtraction operator.
     *
     * @param other Another object to subtract.
     * @return Resulting Matrix after subtraction.
     */
    Matrix& operator-(const IObject& other) const override;

    /**
     * @brief Multiplication operator.
     *
     * @param other Another object to multiply.
     * @return Resulting Matrix after multiplication.
     */
    Matrix& operator*(const IObject& other) const override;

    /**
     * @brief Division operator.
     *
     * @param other Another object to divide.
     * @return Resulting Matrix after division.
     */
    Matrix& operator/(const IObject& other) const override;

    /**
     * @brief Addition assignment operator.
     *
     * @param other Another object to add.
     * @return Reference to this Matrix after addition.
     */
    Matrix& operator+=(const IObject& other) override;

    /**
     * @brief Subtraction assignment operator.
     *
     * @param other Another object to subtract.
     * @return Reference to this Matrix after subtraction.
     */
    Matrix& operator-=(const IObject& other) override;

    /**
     * @brief Multiplication assignment operator.
     *
     * @param other Another object to multiply.
     * @return Reference to this Matrix after multiplication.
     */
    Matrix& operator*=(const IObject& other) override;

    /**
     * @brief Division assignment operator.
     *
     * @param other Another object to divide.
     * @return Reference to this Matrix after division.
     */
    Matrix& operator/=(const IObject& other) override;
    /**
     * @brief Subscript operator.
     *
     * @param index Index of the row to access.
     * @return Reference to the row at the specified index.
     */
    Matrix& operator[](size_t index);

    /**
     * @brief Getter for the data member.
     * @return Reference to the data vector.
     */
    const Matrix &getData() const;

    /**
     * @brief Prefix increment operator.
     * @return Reference to the row at the specified index.
     *
     */
    Matrix &operator++() override requires Incrementable<T>;

    /**
     * @brief Prefix decrement operator.
     * @return Reference to the row at the specified index.
     */
    Matrix &operator--() override requires Incrementable<T>;

    /**

     *
     * @param os Output stream.
     * @param matrix Matrix to insert into the stream.
    */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (const auto& row : matrix.data) {
            for (const auto& elem : row.getData()) {{
                    os << elem << ' ';
                }
                os << '\n';
            }
        }
        return os;
    }

    /**
     * @brief Stream extraction operator.
     *
     * @param is Input stream.
     * @param matrix Matrix to extract from the stream.
    */
    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        for (auto& row : matrix.data) {
            for (auto& elem : row) {
                is >> elem;
            }
        }
        return is;
    }
private:
    std::vector<Vector<T>> data; ///< Data storage for the matrix.
};
#endif //MATRIX_H
