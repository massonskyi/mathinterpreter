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

#ifndef VECTOR_H
#define VECTOR_H
#include "iobject.h"
/**
 * @class Vector
 * @brief A template class that represents a mathematical vector.
 *
 * @tparam T The type of elements stored in the vector.
 *
 * This class provides various operators for vector arithmetic and comparison.
 */
template<typename T>
class Vector final : public IObject {
public:

    /**
     * @brief Default constructor.
     */
    Vector() = default;

    /**
     * @brief Constructor.
     *
     * @param size The size of the vector.
     */
    explicit Vector(size_t size);

    /**
     * @brief Move constructor.
     *
     * @param other The vector to move from.
     */
    Vector(Vector&& other) noexcept;

    /**
     * @brief Destructor.
     */
    ~Vector() override;

    /**
     * @brief Prints the vector.
     */
    void print() const override;

    /**
     * @brief Prefix increment operator.e;
     * @return Reference to the incremented vector.
     */
    Vector& operator++()override requires Incrementable<T>;


    /**
     * @brief Prefix decrement operator.
     * @return Reference to the decremented vector.
     */
    Vector& operator--()override requires Incrementable<T> ;



    /**
     * @brief Modulus operator.
     * @param other The other object to perform the operation with.
     * @return Reference to the result vector.
     */
    Vector& operator%(const IObject& other) const override;

    /**
     * @brief Bitwise AND operator.
     * @param other The other object to perform the operation with.
     * @return Reference to the result vector.
     */
    Vector& operator&(const IObject& other) const override;

    /**
     * @brief Bitwise OR operator.
     *
     * @param other The other object to perform the operation with.
     * @return Reference to the result vector.
     */
    Vector& operator|(const IObject& other) const override;

    /**
     * @brief Bitwise XOR operator.
     *
     * @param other The other object to perform the operation with.
     * @return Reference to the result vector.
     */
    Vector& operator^(const IObject& other) const override;

    /**
     * @brief Bitwise left shift operator.
     *
     * @param other The other object to perform the operation with.
     * @return Reference to the result vector.
     */
    Vector& operator<<(const IObject& other) const override;

    /**
     * @brief Bitwise right shift operator.
     *
     * @param other The other object to perform the operation with.
     * @return Reference to the result vector.
     */
    Vector& operator>>(const IObject& other) const override;

    /**
     * @brief Modulus assignment operator.
     *
     * @param other The other object to perform the operation with.
     * @return Reference to the result vector.
     */
    Vector& operator%=(const IObject& other) override;

    /**
     * @brief Bitwise AND assignment operator.
     *
     * @param other The other object to perform the operation with.
     * @return Reference to the result vector.
     */
    Vector& operator&=(const IObject& other) override;

    /**
     * @brief Bitwise OR assignment operator.
     *
     * @param other The other object to perform the operation with.
     * @return Reference to the result vector.
     */
    Vector& operator|=(const IObject& other) override;

    /**
     * @brief Bitwise XOR assignment operator.
     *
     * @param other The other object to perform the operation with.
     * @return Reference to the result vector.
     */
    Vector& operator^=(const IObject& other) override;

    /**
     * @brief Bitwise left shift assignment operator.
     *
     * @param other The other object to perform the operation with.
     * @return Reference to the result vector.
     */
    Vector& operator<<=(const IObject& other) override;

    /**
     * @brief Bitwise right shift assignment operator.
     *
     * @param other The other object to perform the operation with.
     * @return Reference to the result vector.
     */
    Vector& operator>>=(const IObject& other) override;

    /**
     * @brief Equality operator.
     *
     * @param other The other object to compare with.
     * @return True if the vectors are equal, false otherwise.
     */
    bool operator==(const IObject& other) const override;

    /**
     * @brief Inequality operator.
     *
     * @param other The other object to compare with.
     * @return True if the vectors are not equal, false otherwise.
     */
    bool operator!=(const IObject& other) const override;

    /**
     * @brief Less than operator.
     *
     * @param other The other object to compare with.
     * @return True if this vector is less than the other, false otherwise.
     */
    bool operator<(const IObject& other) const override;

    /**
     * @brief Less than or equal to operator.
     *
     * @param other The other object to compare with.
     * @return True if this vector is less than or equal to the other, false otherwise.
     */
    bool operator<=(const IObject& other) const override;

    /**
     * @brief Greater than operator.
     *
     * @param other The other object to compare with.
     * @return True if this vector is greater than the other, false otherwise.
     */
    bool operator>(const IObject& other) const override;

    /**
     * @brief Greater than or equal to operator.
     *
     * @param other The other object to compare with.
     * @return True if this vector is greater than or equal to the other, false otherwise.
     */
    bool operator>=(const IObject& other) const override;

    /**
     * @brief Addition operator.
     *
     * @param other The other object to add.
     * @return Reference to the result vector.
     */
    Vector& operator+(const IObject& other) const override;

    /**
     * @brief Subtraction operator.
     *
     * @param other The other object to subtract.
     * @return Reference to the result vector.
     */
    Vector& operator-(const IObject& other) const override;

    /**
     * @brief Multiplication operator.
     *
     * @param other The other object to multiply.
     * @return Reference to the result vector.
     */
    Vector& operator*(const IObject& other) const override;

    /**
     * @brief Division operator.
     *
     * @param other The other object to divide.
     * @return Reference to the result vector.
     */
    Vector& operator/(const IObject& other) const override;

    /**
     * @brief Addition assignment operator.
     *
     * @param other The other object to add.
     * @return Reference to the result vector.
     */
    Vector& operator+=(const IObject& other) override;

    /**
     * @brief Subtraction assignment operator.
     *
     * @param other The other object to subtract.
     * @return Reference to the result vector.
     */
    Vector& operator-=(const IObject& other) override;

    /**
     * @brief Multiplication assignment operator.
     *
     * @param other The other object to multiply.
     * @return Reference to the result vector.
     */
    Vector& operator*=(const IObject& other) override;

    /**
     * @brief Division assignment operator.
     *
     * @param other The other object to divide.
     * @return Reference to the result vector.
     */
    Vector& operator/=(const IObject& other) override;

    /**
     * @brief Subscript operator.
     *
     * @param index Index of the element to access.
     * @return Reference to the element at the specified index.
     */
    Vector& operator[](size_t index);

    /**
     * @brief Subscript operator.
     *
     * @param index Index of the element to access.
     * @return Reference to the element at the specified index.
     */
    friend std::ostream& operator<<(std::ostream& os, const Vector& vector) {
        for (const auto& elem : vector.data) {
            os << elem << ' ';
        }
        return os;
    };

    /**
     * @brief Stream extraction operator.
     *
     * @param is Input stream.
     * @param vector Vector to extract from the stream.
     */
    friend std::istream& operator>>(std::istream& is, Vector& vector) {
        for (auto& elem : vector.data) {
            is >> elem;
        }
        return is;
    };
    /**
     * @brief Getter for the data member.
     * @return Reference to the data vector.
     */

    const Vector& getData() const;

private:
    /**
     * @brief A container for storing elements of type T.
     *
     * This vector is used to store a collection of elements of type T.
     * It provides dynamic array functionality, allowing elements to be
     * added, removed, and accessed efficiently.
     *
     * @tparam T The type of elements stored in the vector.
     */
    std::vector<T> data;
};
#endif //VECTOR_H
