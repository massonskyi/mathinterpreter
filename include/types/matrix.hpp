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
#include <iostream>
#include <stdexcept>
#include "vector.hpp" // Предполагается, что Vector<T> объявлен здесь

/**
 * @brief Template class Matrix representing a matrix.
 *
 * @tparam T Type of the elements in the matrix.
 */
template<typename T>
class Matrix final {
public:
    /**
     * @brief Default constructor.
     */
    Matrix() = default;

    /**
     * @brief Constructor that takes the number of rows and columns.
     *
     * @param rows Number of rows.
     * @param cols Number of columns.
     */
    Matrix(int rows, int cols) : data(rows, Vector<T>(cols)) {}

    /**
     * @brief Constructor that takes a vector of vectors.
     *
     * @param vec Vector of vectors representing the rows of the matrix.
     */
    explicit Matrix(const std::vector<Vector<T>>& vec) : data(vec) {}

    /**
     * @brief Move constructor.
     *
     * @param other Another Matrix object to move.
     */
    Matrix(Matrix&& other) noexcept : data(std::move(other.data)) {}

    /**
     * @brief Destructor.
     */
    ~Matrix() = default;

    /**
     * @brief Prints the contents of the matrix.
     */
    void print() const {
        std::cout << *this; // Используем перегруженный оператор вывода
    }

    /**
     * @brief Returns the number of rows.
     */
    int getRows() const {
        return data.size();
    }

    /**
     * @brief Returns the number of columns.
     */
    int getCols() const {
        return data.empty() ? 0 : data[0].size();
    }

    /**
     * @brief Equality comparison operator.
     */
    bool operator==(const Matrix& other) const {
        return data == other.data;
    }

    /**
     * @brief Inequality comparison operator.
     */
    bool operator!=(const Matrix& other) const {
        return !(*this == other);
    }

    /**
     * @brief Less than comparison operator.
     */
    bool operator<(const Matrix& other) const {
        return data < other.data; // Сравнение по строкам
    }

    /**
     * @brief Less than or equal to comparison operator.
     */
    bool operator<=(const Matrix& other) const {
        return *this < other || *this == other;
    }

    /**
     * @brief Greater than comparison operator.
     */
    bool operator>(const Matrix& other) const {
        return !(*this <= other);
    }

    /**
     * @brief Greater than or equal to comparison operator.
     */
    bool operator>=(const Matrix& other) const {
        return !(*this < other);
    }

    /**
     * @brief Addition operator.
     */
    Matrix operator+(Matrix& other){
        if (getRows() != other.getRows() || getCols() != other[0].size()) {
            throw std::invalid_argument("Matrices are not compatible for addition: size mismatch.");
        }

        Matrix result;
        for (size_t i = 0; i < data.size(); ++i) {
            result.data.push_back(data[i] + other.data[i]);
        }
        return result;
    }

    /**
     * @brief Subtraction operator.
     */
    Matrix operator-(const Matrix& other) const {
        if (data.size() != other.data.size() || data[0].size() != other.data[0].size()) {
            throw std::invalid_argument("Matrices are not compatible for subtraction: size mismatch.");
        }

        Matrix result;
        for (size_t i = 0; i < data.size(); ++i) {
            result.data.push_back(data[i] - other.data[i]);
        }
        return result;
    }

    /**
     * @brief Multiplication operator.
     */
    Matrix operator*(Matrix& other) {
        // Check if the matrices can be multiplied
        if (data.empty() || data[0].size() != other.data.size()) {
            throw std::invalid_argument("Matrices are not compatible for multiplication: size mismatch.");
        }

        // Create a result matrix with the appropriate size
        Matrix result;
        result.data.resize(data.size(), Vector<T>(other.data[0].size())); // Initialize result with zeros

        for (size_t i = 0; i < data.size(); ++i) { // Loop through rows of the first matrix
            for (size_t j = 0; j < other.data[0].size(); ++j) { // Loop through columns of the second matrix
                T sum = 0;
                for (size_t k = 0; k < data[0].size(); ++k) { // Loop through columns of the first matrix / rows of the second
                    sum += data[i][k] * other.data[k][j]; // Calculate the sum for the result element
                }
                result.data[i][j] = sum; // Assign the computed value to the result matrix
            }
        }
        return result;
    }

    /**
     * @brief Division operator.
     */
    Matrix operator/(const T& scalar) const {
        Matrix result = *this; // Копируем текущую матрицу
        for (auto& row : result.data) {
            for (auto& element : row) {
                element /= scalar; // Предполагается, что T поддерживает деление
            }
        }
        return result;
    }

    /**
     * @brief Addition assignment operator.
     */
    Matrix& operator+=(const Matrix& other) {
        *this = *this + other;
        return *this;
    }

    /**
     * @brief Subtraction assignment operator.
     */
    Matrix& operator-=(const Matrix& other) {
        *this = *this - other;
        return *this;
    }

    /**
     * @brief Multiplication assignment operator.
     */
    Matrix& operator*=(const Matrix& other) {
        *this = *this * other;
        return *this;
    }

    /**
     * @brief Division assignment operator.
     */
    Matrix& operator/=(const T& scalar) {
        *this = *this / scalar;
        return *this;
    }

    /**
     * @brief Subscript operator.
     */
    Vector<T>& operator[](size_t index){
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range.");
        }
        return data[index];
    }

    /**
     * @brief Getter for the data member.
     * @return Reference to the data vector.
     */
    const std::vector<Vector<T>>& getData() const {
        return data;
    }

    /**
     * @brief Prefix increment operator.
     * @return Reference to this Matrix.
     */
    Matrix& operator++() {
        for (auto& row : data) {
            ++row; // Предполагается, что Vector<T> поддерживает инкремент
        }
        return *this;
    }

    /**
     * @brief Prefix decrement operator.
     * @return Reference to this Matrix.
     */
    Matrix& operator--() {
        for (auto& row : data) {
            --row; // Предполагается, что Vector<T> поддерживает декремент
        }
        return *this;
    }

    /**
     * @brief Stream extraction operator.
     */
    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        for (auto& row : matrix.data) {
            is >> row; // Предполагается, что Vector<T> поддерживает ввод
        }
        return is;
    }

    /**
     * @brief Stream insertion operator.
     */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (const auto& row : matrix.getData()) {
            os << row << '\n'; // Предполагается, что Vector<T> перегружает оператор вывода
        }
        return os;
    }

private:
    std::vector<Vector<T>> data; ///< Data storage for the matrix.
};

#endif // MATRIX_H
