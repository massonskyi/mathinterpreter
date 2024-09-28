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
#ifndef NUMBER_H
#define NUMBER_H
#include "iobject.h"

/**
 * @brief A class representing a number.
 * 
 * @tparam T The type of the number.
 */
template<typename T>
/**
 * @class Number
 * @brief Represents a number object.
 * 
 * This class inherits from the IObject interface and provides various mathematical operations.
 */
class Number : public IObject {
    MI_API
public:
    /**
     * @brief Default constructor.
     * 
     * Initializes the number to 0.
     */
    Number();

    /**
     * @brief Constructor with value.
     * 
     * @param val The value to initialize the number with.
     */
    Number(T val);

    /**
     * @brief Copy constructor.
     * 
     * @param other The number to copy from.
     */
    Number(const Number& other);

    /**
     * @brief 
     */
    Number(const Number&& other);
    /**
     * @brief Prints the number.
     */
    void print() const override;

    /**
     * @brief Prefix increment operator.
     * 
     * @return The incremented number.
     */
    IObject& operator++() override;

    /**
     * @brief Prefix decrement operator.
     * 
     * @return The decremented number.
     */
    IObject& operator--() override;

    /**
     * @brief Modulo operator.
     * 
     * @param other The other number to perform the modulo operation with.
     * @return The result of the modulo operation.
     */
    IObject& operator%(const IObject& other) const override;

    /**
     * @brief Equality operator.
     * 
     * @param other The other number to compare with.
     * @return True if the numbers are equal, false otherwise.
     */
    bool operator==(const IObject& other) const override;

    /**
     * @brief Inequality operator.
     * 
     * @param other The other number to compare with.
     * @return True if the numbers are not equal, false otherwise.
     */
    bool operator!=(const IObject& other) const override;

    /**
     * @brief Less than operator.
     * 
     * @param other The other number to compare with.
     * @return True if this number is less than the other number, false otherwise.
     */
    bool operator<(const IObject& other) const override;

    /**
     * @brief Less than or equal to operator.
     * 
     * @param other The other number to compare with.
     * @return True if this number is less than or equal to the other number, false otherwise.
     */
    bool operator<=(const IObject& other) const override;

    /**
     * @brief Greater than operator.
     * 
     * @param other The other number to compare with.
     * @return True if this number is greater than the other number, false otherwise.
     */
    bool operator>(const IObject& other) const override;

    /**
     * @brief Greater than or equal to operator.
     * 
     * @param other The other number to compare with.
     * @return True if this number is greater than or equal to the other number, false otherwise.
     */
    bool operator>=(const IObject& other) const override;

    /**
     * @brief Addition operator.
     * 
     * @param other The other number to add.
     * @return The result of the addition.
     */
    IObject& operator+(const IObject& other) const override;

    /**
     * @brief Subtraction operator.
     * 
     * @param other The other number to subtract.
     * @return The result of the subtraction.
     */
    IObject& operator-(const IObject& other) const override;

    /**
     * @brief Multiplication operator.
     * 
     * @param other The other number to multiply.
     * @return The result of the multiplication.
     */
    IObject& operator*(const IObject& other) const override;

    /**
     * @brief Division operator.
     * 
     * @param other The other number to divide.
     * @return The result of the division.
     */
    IObject& operator/(const IObject& other) const override;

    /**
     * @brief Addition assignment operator.
     * 
     * @param other The other number to add.
     * @return The updated number after addition.
     */
    IObject& operator+=(const IObject& other) override;

    /**
     * @brief Subtraction assignment operator.
     * 
     * @param other The other number to subtract.
     * @return The updated number after subtraction.
     */
    IObject& operator-=(const IObject& other) override;

    /**
     * @brief Multiplication assignment operator.
     * 
     * @param other The other number to multiply.
     * @return The updated number after multiplication.
     */
    IObject& operator*=(const IObject& other) override;

    /**
     * @brief Division assignment operator.
     * 
     * @param other The other number to divide.
     * @return The updated number after division.
     */
    IObject& operator/=(const IObject& other) override;

    inline T get_value() const;


private:
    T value;
};

template<typename T>
Number<T>::Number(T value) {

}

template<typename T>
Number<T>::Number(const Number &other) {
    
}

#endif //NUMBER_H
