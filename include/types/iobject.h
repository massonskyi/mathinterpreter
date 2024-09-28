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

#ifndef IOBJECT_H
#define IOBJECT_H
#include "../mod/objects.h"
/**
 * @class IObject
 * @brief An abstract base class that defines a common interface for objects.
 *
 * This class provides a set of pure virtual functions for various operators
 * and comparison methods that derived classes must implement.
 */
class IObject {
    MI_API
public:
    /**
     * @brief Default constructor.
     */
    IObject() = default;

    /**
     * @brief Copy constructor.
     * @param other The object to copy from.
     */
    IObject(const IObject& other) = default;

    /**
     * @brief Move constructor.
     * @param other The object to move from.
     */
    IObject(IObject&& other) = default;

    /**
     * @brief Virtual destructor.
     */
    virtual ~IObject() = default;

    /**
     * @brief Print the object.
     */
    virtual void print() const = 0;

    /**
     * @brief Prefix increment operator.
     * @return Reference to the incremented object.      
     * */
     virtual IObject& operator++() = 0;

    /**
     * @brief Prefix decrement operator.
     * @return Reference to the decremented object.
     */
    virtual IObject& operator--() = 0;

    /**
     * @brief Modulus operator.
     * @param other The object to perform the operation with.
     * @return Reference to the result.
     */
    virtual IObject& operator%(const IObject& other) const = 0;

    /**
     * @brief Equality operator.
     * @param other The object to compare with.
     * @return True if the objects are equal, false otherwise.
     */
    virtual bool operator==(const IObject& other) const = 0;

    /**
     * @brief Inequality operator.
     * @param other The object to compare with.
     * @return True if the objects are not equal, false otherwise.
     */
    virtual bool operator!=(const IObject& other) const = 0;

    /**
     * @brief Less than operator.
     * @param other The object to compare with.
     * @return True if this object is less than the other, false otherwise.
     */
    virtual bool operator<(const IObject& other) const = 0;

    /**
     * @brief Less than or equal to operator.
     * @param other The object to compare with.
     * @return True if this object is less than or equal to the other, false otherwise.
     */
    virtual bool operator<=(const IObject& other) const = 0;

    /**
     * @brief Greater than operator.
     * @param other The object to compare with.
     * @return True if this object is greater than the other, false otherwise.
     */
    virtual bool operator>(const IObject& other) const = 0;

    /**
     * @brief Greater than or equal to operator.
     * @param other The object to compare with.
     * @return True if this object is greater than or equal to the other, false otherwise.
     */
    virtual bool operator>=(const IObject& other) const = 0;

    /**
     * @brief Addition operator.
     * @param other The object to add.
     * @return Reference to the result.
     */
    virtual IObject& operator+(const IObject& other) const = 0;

    /**
     * @brief Subtraction operator.
     * @param other The object to subtract.
     * @return Reference to the result.
     */
    virtual IObject& operator-(const IObject& other) const = 0;

    /**
     * @brief Multiplication operator.
     * @param other The object to multiply.
     * @return Reference to the result.
     */
    virtual IObject& operator*(const IObject& other) const = 0;

    /**
     * @brief Division operator.
     * @param other The object to divide.
     * @return Reference to the result.
     */
    virtual IObject& operator/(const IObject& other) const = 0;

    /**
     * @brief Addition assignment operator.
     * @param other The object to add.
     * @return Reference to the result.
     */
    virtual IObject& operator+=(const IObject& other) = 0;

    /**
     * @brief Subtraction assignment operator.
     * @param other The object to subtract.
     * @return Reference to the result.
     */
    virtual IObject& operator-=(const IObject& other) = 0;

    /**
     * @brief Multiplication assignment operator.
     * @param other The object to multiply.
     * @return Reference to the result.
     */
    virtual IObject& operator*=(const IObject& other) = 0;

    /**
     * @brief Division assignment operator.
     * @param other The object to divide.
     * @return Reference to the result.
     */
    virtual IObject& operator/=(const IObject& other) = 0;
};
#endif //IOBJECT_H
