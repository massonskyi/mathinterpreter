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

#include <iostream>
#include <vector>
#include <stdexcept>
#include <numeric> // Для std::accumulate
#include <iterator> // Add this line to include the <iterator> header

/**
 * @class Vector
 * @brief A template class that represents a mathematical vector.
 *
 * @tparam T The type of elements stored in the vector.
 *
 * This class provides various operators for vector arithmetic and comparison.
 */
template<typename T>
class Vector final {
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
    explicit Vector(size_t size) : data(size) {}

    /**
     * @brief Move constructor.
     *
     * @param other The vector to move from.
     */
    Vector(Vector&& other) noexcept : data(std::move(other.data)) {}
    /**
     * @brief Copy constructor 
     * 
     * @param other The vector to copy from.
     */
    Vector(const Vector& other) : data(other.data) {}
    /**
     * @brief Destructor.
     */
    ~Vector() = default;

    /**
     * @brief Prints the vector.
     */
    void print() const {
        for (const auto& elem : data) {
            std::cout << elem << ' ';
        }
        std::cout << std::endl;
    }

    /**
     * @brief Prefix increment operator.
     * @return Reference to the incremented vector.
     */
    Vector& operator++() requires std::is_arithmetic_v<T> {
        for (auto& elem : data) {
            ++elem;
        }
        return *this;
    }

    /**
     * @brief Prefix decrement operator.
     * @return Reference to the decremented vector.
     */
    Vector& operator--() requires std::is_arithmetic_v<T> {
        for (auto& elem : data) {
            --elem;
        }
        return *this;
    }

    /**
     * @brief Modulus operator.
     * @param other The other vector to perform the operation with.
     * @return A new vector representing the modulus.
     */
    Vector operator%(const Vector& other) const {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Vectors must have the same size.");
        }
        Vector result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] % other.data[i];
        }
        return result;
    }

    /**
     * @brief Equality operator.
     *
     * @param other The other vector to compare with.
     * @return True if the vectors are equal, false otherwise.
     */
    bool operator==(const Vector& other) const {
        return data == other.data;
    }

    /**
     * @brief Inequality operator.
     *
     * @param other The other vector to compare with.
     * @return True if the vectors are not equal, false otherwise.
     */
    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }

    /**
     * @brief Less than operator.
     *
     * @param other The other vector to compare with.
     * @return True if this vector is less than the other, false otherwise.
     */
    bool operator<(const Vector& other) const {
        return std::lexicographical_compare(data.begin(), data.end(), other.data.begin(), other.data.end());
    }

    /**
     * @brief Less than or equal to operator.
     *
     * @param other The other vector to compare with.
     * @return True if this vector is less than or equal to the other, false otherwise.
     */
    bool operator<=(const Vector& other) const {
        return *this < other || *this == other;
    }

    /**
     * @brief Greater than operator.
     *
     * @param other The other vector to compare with.
     * @return True if this vector is greater than the other, false otherwise.
     */
    bool operator>(const Vector& other) const {
        return !(*this <= other);
    }

    /**
     * @brief Greater than or equal to operator.
     *
     * @param other The other vector to compare with.
     * @return True if this vector is greater than or equal to the other, false otherwise.
     */
    bool operator>=(const Vector& other) const {
        return !(*this < other);
    }

    /**
     * @brief Addition operator.
     *
     * @param other The other vector to add.
     * @return A new vector representing the sum.
     */
    Vector operator+(const Vector& other) const {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Vectors must have the same size.");
        }
        Vector result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    /**
     * @brief Subtraction operator.
     *
     * @param other The other vector to subtract.
     * @return A new vector representing the difference.
     */
    Vector operator-(const Vector& other) const {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Vectors must have the same size.");
        }
        Vector result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    /**
     * @brief Multiplication operator.
     *
     * @param other The other vector to multiply.
     * @return A new vector representing the product.
     */
    Vector operator*(const Vector& other) const {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Vectors must have the same size.");
        }
        Vector result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] * other.data[i];
        }
        return result;
    }

    /**
     * @brief Division operator.
     *
     * @param other The other vector to divide.
     * @return A new vector representing the quotient.
     */
    Vector operator/(const Vector& other) const {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Vectors must have the same size.");
        }
        Vector result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            if (other.data[i] == 0) {
                throw std::invalid_argument("Cannot divide by zero.");
            }
            result.data[i] = data[i] / other.data[i];
        }
        return result;
    }

    /**
     * @brief Addition assignment operator.
     *
     * @param other The other vector to add.
     * @return Reference to the current vector after addition.
     */
    Vector& operator+=(const Vector& other) {
        *this = *this + other;
        return *this;
    }

    /**
     * @brief Subtraction assignment operator.
     *
     * @param other The other vector to subtract.
     * @return Reference to the current vector after subtraction.
     */
    Vector& operator-=(const Vector& other) {
        *this = *this - other;
        return *this;
    }

    /**
     * @brief Multiplication assignment operator.
     *
     * @param other The other vector to multiply.
     * @return Reference to the current vector after multiplication.
     */
    Vector& operator*=(const Vector& other) {
        *this = *this * other;
        return *this;
    }

    /**
     * @brief Division assignment operator.
     *
     * @param other The other vector to divide.
     * @return Reference to the current vector after division.
     */
    Vector& operator/=(const Vector& other) {
        *this = *this / other;
        return *this;
    }
    
    /**
     * @brief Get data
     */
    inline std::vector<T> getData() const {
        return data;
    }

    /**
     * @brief Get the size of the vector.
     * @return The size of the vector.
     */
    size_t size() const {
        return data.size();
    }

    /**
     * @brief Const subscript operator.
     *
     * @param index Index of the element to access.
     * @return Reference to the element at the specified index.
     */
    T& operator[](size_t index){
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range.");
        }
        return data[index];
    }
    
    /**
     * @brief Const subscript operator.
     * 
     * @param other The vector
     */
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

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
    }
    /**
     * @brief Stream insertion operator.
     * @param os Output stream.
     * @param vec Vector to insert into the stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
        for (const auto& element : vec.data) {
            os << element << ' ';
        }
        return os;
    }

private:
    std::vector<T> data; ///< Container for storing elements of type T.
};

#endif // VECTOR_H
