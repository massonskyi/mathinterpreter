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

#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <concepts>



#endif // TYPES_H


template<typename T>
Vector<T>::Vector(size_t size) {
    data.resize(size);
};

template<typename T>
Vector<T>::Vector(Vector&& other) noexcept {
    data = std::move(other.data);
};

template<typename T>
Vector<T>::~Vector() = default;

template<typename T>
void Vector<T>::print() const {
    for (const auto& elem : data) {
        std::cout << elem << ' ';
    }
};

template<typename T>

Vector<T>& Vector<T>::operator++() requires Incrementable<T>{
    for (auto& elem : data) {
        ++elem;
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator--() requires Incrementable<T> {
    for (auto& elem : data) {
        --elem;
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator%(const IObject& other) const {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] % otherVector->data[i];
        }
        return result;
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Modulus operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] % otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
        return result;
    } else {
        throw std::invalid_argument("Unsupported type for modulus operation.");
    }
}

template<typename T>
Vector<T>& Vector<T>::operator&(const IObject& other) const {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] & otherVector->data[i];
        }
        return result;
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Bitwise AND operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] & otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
        return result;
    } else {
        throw std::invalid_argument("Unsupported type for bitwise AND operation.");
    }
}

template<typename T>
Vector<T>& Vector<T>::operator|(const IObject& other) const {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] | otherVector->data[i];
        }
        return result;
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Bitwise OR operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] | otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
        return result;
    } else {
        throw std::invalid_argument("Unsupported type for bitwise OR operation.");
    }
}

template<typename T>
Vector<T>& Vector<T>::operator^(const IObject& other) const {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] ^ otherVector->data[i];
        }
        return result;
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Bitwise XOR operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] ^ otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
        return result;
    } else {
        throw std::invalid_argument("Unsupported type for bitwise XOR operation.");
    }
}

template<typename T>
Vector<T>& Vector<T>::operator<<(const IObject& other) const {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] << otherVector->data[i];
        }
        return result;
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Bitwise left shift operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] << otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
        return result;
    } else {
        throw std::invalid_argument("Unsupported type for bitwise left shift operation.");
    }
}

template<typename T>
Vector<T>& Vector<T>::operator>>(const IObject& other) const {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] >> otherVector->data[i];
        }
        return result;
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Bitwise right shift operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] >> otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
        return result;
    } else {
        throw std::invalid_argument("Unsupported type for bitwise right shift operation.");
    }
}

template<typename T>
Vector<T>& Vector<T>::operator%=(const IObject& other) {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] %= otherVector->data[i];
        }
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Modulus assignment operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] %= otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
    } else {
        throw std::invalid_argument("Unsupported type for modulus assignment operation.");
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator&=(const IObject& other) {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] &= otherVector->data[i];
        }
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Bitwise AND assignment operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] &= otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
    } else {
        throw std::invalid_argument("Unsupported type for bitwise AND assignment operation.");
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator|=(const IObject& other) {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] |= otherVector->data[i];
        }
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Bitwise OR assignment operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] |= otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
    } else {
        throw std::invalid_argument("Unsupported type for bitwise OR assignment operation.");
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator^=(const IObject& other) {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] ^= otherVector->data[i];
        }
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Bitwise XOR assignment operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] ^= otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
    } else {
        throw std::invalid_argument("Unsupported type for bitwise XOR assignment operation.");
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator<<=(const IObject& other) {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] <<= otherVector->data[i];
        }
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Bitwise left shift assignment operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] <<= otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
    } else {
        throw std::invalid_argument("Unsupported type for bitwise left shift assignment operation.");
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator>>=(const IObject& other) {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] >>= otherVector->data[i];
        }
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Bitwise right shift assignment operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] >>= otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
    } else {
        throw std::invalid_argument("Unsupported type for bitwise right shift assignment operation.");
    }
    return *this;
}

template<typename T>
bool Vector<T>::operator==(const IObject& other) const {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        return data == otherVector->data;
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        return false;
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        return false;
    } else {
        throw std::invalid_argument("Unsupported type for equality comparison.");
    }
}

template<typename T>
bool Vector<T>::operator!=(const IObject& other) const {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        return data != otherVector->data;
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        return true;
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        return true;
    } else {
        throw std::invalid_argument("Unsupported type for inequality comparison.");
    }
}

template<typename T>
bool Vector<T>::operator<(const IObject& other) const {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        return data < otherVector->data;
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        return false;
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        return false;
    } else {
        throw std::invalid_argument("Unsupported type for less than comparison.");
    }
}

template<typename T>
bool Vector<T>::operator<=(const IObject& other) const {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        return data <= otherVector->data;
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        return false;
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        return false;
    } else {
        throw std::invalid_argument("Unsupported type for less than or equal to comparison.");
    }
}

template<typename T>
bool Vector<T>::operator>(const IObject& other) const {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        return data > otherVector->data;
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        return false;
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        return false;
    } else {
        throw std::invalid_argument("Unsupported type for greater than comparison.");
    }
}

template<typename T>
bool Vector<T>::operator>=(const IObject& other) const {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        return data >= otherVector->data;
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        return false;
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        return false;
    } else {
        throw std::invalid_argument("Unsupported type for greater than or equal to comparison.");
    }
}

template<typename T>
Vector<T>& Vector<T>::operator+(const IObject& other) const {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] + otherVector->data[i];
        }
        return result;
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Addition operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] + otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
        return result;
    } else {
        throw std::invalid_argument("Unsupported type for addition operation.");
    }
}

template<typename T>
Vector<T>& Vector<T>::operator-(const IObject& other) const {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] - otherVector->data[i];
        }
        return result;
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Subtraction operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] - otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
        return result;
    } else {
        throw std::invalid_argument("Unsupported type for subtraction operation.");
    }
}

template<typename T>
Vector<T>& Vector<T>::operator*(const IObject& other) const {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] * otherVector->data[i];
        }
        return result;
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Multiplication operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] * otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
        return result;
    } else {
        throw std::invalid_argument("Unsupported type for multiplication operation.");
    }
}
template<typename T>
Vector<T>& Vector<T>::operator/(const IObject& other) const {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] / otherVector->data[i];
        }
        return result;
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Division operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] / otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
        return result;
    } else {
        throw std::invalid_argument("Unsupported type for division operation.");
    }
}
template<typename T> 
Vector<T>& Vector<T>::operator+=(const IObject& other) {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] += otherVector->data[i];
        }
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Addition assignment operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] += otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
    } else {
        throw std::invalid_argument("Unsupported type for addition assignment operation.");
    }
    return *this;
}
template<typename T>
Vector<T>& Vector<T>::operator-=(const IObject& other) {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] -= otherVector->data[i];
        }
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Subtraction assignment operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] -= otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
    } else {
        throw std::invalid_argument("Unsupported type for subtraction assignment operation.");
    }
    return *this;
}
template<typename T>
Vector<T>& Vector<T>::operator*=(const IObject& other) {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] *= otherVector->data[i];
        }
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Multiplication assignment operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] *= otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
    } else {
        throw std::invalid_argument("Unsupported type for multiplication assignment operation.");
    }
    return *this;
}
template<typename T>
Vector<T>& Vector<T>::operator/=(const IObject& other) {
    if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] /= otherVector->data[i];
        }
    } else if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        throw std::invalid_argument("Division assignment operation not supported between Vector and Matrix.");
    } else if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] /= otherRational->getNumerator(); // Assuming Rational has getNumerator method
        }
    } else {
        throw std::invalid_argument("Unsupported type for division assignment operation.");
    }
    return *this;
}
template<typename T>
Vector<T>& Vector<T>::operator[](size_t index) {
    return data[index];
}

template<typename T>
const Vector<T>& Vector<T>::getData() const {
    return data;
}

template<typename T>
Matrix<T>::Matrix(const Vector<T>& vec) {
    data = vec.getData();
}

template<typename T>
void Matrix<T>::print () const {
    for (const auto& row : data) {
        row.print();
        std::cout << '\n';
    }
}

template<typename T>
bool Matrix<T>::operator==(const IObject& other) const {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        return data == otherMatrix->data;
    }

    return false;
}

template<typename T>
bool Matrix<T>::operator!=(const IObject& other) const {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        return data != otherMatrix->data;
    }
    return true;
}
template<typename T>
bool Matrix<T>::operator<(const IObject& other) const {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        return data < otherMatrix->data;
    }
    return false;
}
template<typename T>
bool Matrix<T>::operator<=(const IObject& other) const {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        return data <= otherMatrix->data;
    } else {
        return false;
    }
}
template<typename T>
bool Matrix<T>::operator>(const IObject& other) const {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        return data > otherMatrix->data;
    } else {
        return false;
    }
}
template<typename T>
bool Matrix<T>::operator>=(const IObject& other) const {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        return data >= otherMatrix->data;
    } else {
        return false;
    }
}
template<typename T>
Matrix<T>& Matrix<T>::operator+(const IObject& other) const {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        Matrix<T> result;
        result.data.resize(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] + otherMatrix->data[i];
        }
        return result;
    } else if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        if (data.size() != otherVector->size()) {
            throw std::invalid_argument("Matrix and Vector size mismatch for addition.");
        }
        Matrix<T> result;
        result.data.resize(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] + otherVector->operator[](i);
        }
        return result;
    } else {
        throw std::invalid_argument("Addition operation not supported between Matrix and non-Matrix/Vector.");
    }
}
template<typename T>
Matrix<T>& Matrix<T>::operator-(const IObject& other) const {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        Matrix<T> result;
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] - otherMatrix->data[i];
        }
        return result;
    } else if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        if (data.size() != otherVector->size()) {
            throw std::invalid_argument("Matrix and Vector size mismatch for subtraction.");
        }
        Matrix<T> result;
        result.data.resize(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] - otherVector->operator[](i);
        }
        return result;
    } else {
        throw std::invalid_argument("Subtraction operation not supported between Matrix and non-Matrix/Vector.");
    }
}
template<typename T>
Matrix<T>& Matrix<T>::operator*(const IObject& other) const {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        Matrix<T> result;
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] * otherMatrix->data[i];
        }
        return result;
    } else if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        if (data.size() != otherVector->size()) {
            throw std::invalid_argument("Matrix and Vector size mismatch for multiplication.");
        }
        Vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result[i] = std::inner_product(data[i].begin(), data[i].end(), otherVector->begin(), T{});
        }
        return result;
    } else {
        throw std::invalid_argument("Multiplication operation not supported between Matrix and non-Matrix/Vector.");
    }
}
template<typename T>
Matrix<T>& Matrix<T>::operator/(const IObject& other) const {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        Matrix<T> result;
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] / otherMatrix->data[i];
        }
        return result;
    } else if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        if (data.size() != otherVector->size()) {
            throw std::invalid_argument("Matrix and Vector size mismatch for division.");
        }
        Matrix<T> result;
        result.data.resize(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] / otherVector->operator[](i);
        }
        return result;
    } else {
        throw std::invalid_argument("Division operation not supported between Matrix and non-Matrix/Vector.");
    }
}
template<typename T>
Matrix<T>& Matrix<T>::operator+=(const IObject& other) {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] += otherMatrix->data[i];
        }
    } else if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        if (data.size() != otherVector->size()) {
            throw std::invalid_argument("Matrix and Vector size mismatch for addition assignment.");
        }
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] += otherVector->operator[](i);
        }
    } else {
        throw std::invalid_argument("Addition assignment operation not supported between Matrix and non-Matrix/Vector.");
    }
    return *this;
}
template<typename T>
Matrix<T>& Matrix<T>::operator-=(const IObject& other) {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] -= otherMatrix->data[i];
        }
    } else if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        if (data.size() != otherVector->size()) {
            throw std::invalid_argument("Matrix and Vector size mismatch for subtraction assignment.");
        }
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] -= otherVector->operator[](i);
        }
    } else {
        throw std::invalid_argument("Subtraction assignment operation not supported between Matrix and non-Matrix/Vector.");
    }
    return *this;
}
template<typename T>
Matrix<T>& Matrix<T>::operator*=(const IObject& other) {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] *= otherMatrix->data[i];
        }
    } else if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        if (data.size() != otherVector->size()) {
            throw std::invalid_argument("Matrix and Vector size mismatch for multiplication assignment.");
        }
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] = std::inner_product(data[i].begin(), data[i].end(), otherVector->begin(), T{});
        }
    } else {
        throw std::invalid_argument("Multiplication assignment operation not supported between Matrix and non-Matrix/Vector.");
    }
    return *this;
}
template<typename T>
Matrix<T>& Matrix<T>::operator/=(const IObject& other) {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] /= otherMatrix->data[i];
        }
    } else if (const auto* otherVector = dynamic_cast<const Vector<T>*>(&other)) {
        if (data.size() != otherVector->size()) {
            throw std::invalid_argument("Matrix and Vector size mismatch for division assignment.");
        }
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] /= otherVector->operator[](i);
        }
    } else {
        throw std::invalid_argument("Division assignment operation not supported between Matrix and non-Matrix/Vector.");
    }
    return *this;
}
template<typename T>
Matrix<T>& Matrix<T>::operator[](size_t index) {
    return data[index];
}
template<typename T>
const Matrix<T>& Matrix<T>::getData() const {
    return data;
}
template<typename T>
Matrix<T>& Matrix<T>::operator++() requires Incrementable<T> {
    for (auto& row : data) {
        for (auto& elem : row.getData()) {
            ++elem;
        }
    }
    return *this;
}
template<typename T>
Matrix<T>& Matrix<T>::operator--() requires Incrementable<T> {
    for (auto& row : data) {
        for (auto& elem : row.getData()) {
            --elem;
        }
    }
    return *this;
}

template<typename T>
Rational<T>::Rational(T numerator, T denominator) : numerator(numerator), denominator(denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
}
template<typename T>
Rational<T>::Rational(const Rational& other) : numerator(other.numerator), denominator(other.denominator) {}
template<typename T>
Rational<T>::Rational(Rational&& other) noexcept : numerator(std::move(other.numerator)), denominator(std::move(other.denominator)) {}
template<typename T>
Rational<T>& Rational<T>::operator=(const Rational& other) {
    if (this != &other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}
template<typename T>
Rational<T>& Rational<T>::operator=(Rational&& other) noexcept {
    if (this != &other) {
        numerator = std::move(other.numerator);
        denominator = std::move(other.denominator);
    }
    return *this;
}
template<typename T>
Rational<T>& Rational<T>::operator+(const IObject& other) const {
    if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        return Rational(numerator * otherRational->denominator + otherRational->numerator * denominator, denominator * otherRational->denominator);
    } else {
        throw std::invalid_argument("Addition operation not supported between Rational and non-Rational.");
    }
}
template<typename T>
Rational<T>& Rational<T>::operator-(const IObject& other) const {
    if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        return Rational(numerator * otherRational->denominator - otherRational->numerator * denominator, denominator * otherRational->denominator);
    } else {
        throw std::invalid_argument("Subtraction operation not supported between Rational and non-Rational.");
    }
}
template<typename T>
Rational<T>& Rational<T>::operator*(const IObject& other) const {
    if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        return Rational(numerator * otherRational->numerator, denominator * otherRational->denominator);
    } else {
        throw std::invalid_argument("Multiplication operation not supported between Rational and non-Rational.");
    }
}
template<typename T>
Rational<T>& Rational<T>::operator/(const IObject& other) const {
    if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        return Rational(numerator * otherRational->denominator, denominator * otherRational->numerator);
    } else {
        throw std::invalid_argument("Division operation not supported between Rational and non-Rational.");
    }
}
template<typename T>
Rational<T>& Rational<T>::operator%(const IObject& other) const {
    if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        return Rational(numerator % otherRational->numerator, denominator % otherRational->denominator);
    } else {
        throw std::invalid_argument("Modulus operation not supported between Rational and non-Rational.");
    }
}
template<typename T>
Rational<T>& Rational<T>::operator+=(const IObject& other) {
    if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        numerator = numerator * otherRational->denominator + otherRational->numerator * denominator;
        denominator *= otherRational->denominator;
    } else {
        throw std::invalid_argument("Addition assignment operation not supported between Rational and non-Rational.");
    }
    return *this;
}
template<typename T>
Rational<T>& Rational<T>::operator-=(const IObject& other) {
    if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        numerator = numerator * otherRational->denominator - otherRational->numerator * denominator;
        denominator *= otherRational->denominator;
    } else {
        throw std::invalid_argument("Subtraction assignment operation not supported between Rational and non-Rational.");
    }
    return *this;
}
template<typename T>
Rational<T>& Rational<T>::operator*=(const IObject& other) {
    if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        numerator *= otherRational->numerator;
        denominator *= otherRational->denominator;
    } else {
        throw std::invalid_argument("Multiplication assignment operation not supported between Rational and non-Rational.");
    }
    return *this;
}
template<typename T>
Rational<T>& Rational<T>::operator/=(const IObject& other) {
    if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
        numerator *= otherRational->denominator;
        denominator *= otherRational->numerator;
    } else {
        throw std::invalid_argument("Division assignment operation not supported between Rational and non-Rational.");
    }
    return *this;
}
// template<typename T>
// Rational<T>& Rational<T>::operator%(const IObject& other) {
//     if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
//         numerator %= otherRational->numerator;
//         denominator %= otherRational->denominator;
//     } else {
//         throw std::invalid_argument("Modulus assignment operation not supported between Rational and non-Rational.");
//     }
//     return *this;
// }
// template<typename T>
// Rational<T>& Rational<T>::operator++() requires Incrementable<T> {
//     numerator += denominator;
//     return *this;
// }

// template<typename T>
// Rational<T>& Rational<T>::operator--() requires Incrementable<T> {
//     numerator -= denominator;
//     return *this;
// }

// template<typename T>
// bool Rational<T>::operator==(const IObject& other) const {
//     if (const auto* otherRational = dynamic_cast<const Rational<T>*>(&other)) {
//         return numerator == otherRational->numerator && denominator == otherRational->denominator;
//     } else {
//         return false;
//     }
// }
#endif // TYPES_H