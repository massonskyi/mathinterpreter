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


#include <vector>
#include <iostream>
#include <concepts>

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
 * @class IObject
 * @brief An abstract base class that defines a common interface for objects.
 * 
 * This class provides a set of pure virtual functions for various operators 
 * and comparison methods that derived classes must implement.
 */
class IObject {
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
     * @return Reference to the incremented object.      */   
     virtual IObject& operator++() = 0;

    /**      
     * @brief Postfix increment operator.b     
     * @return The incremented object.t     
     */    
    virtual IObject operator++(int) = 0 ;

    /**
     * @brief Prefix decrement operator.
     * @return Reference to the decremented object.
     */
    virtual IObject& operator--() = 0;
    /**
     * @brief Postfix decrement operator.      
     * @return The decremented object.l     
     */   
     virtual IObject operator--(int) = 0;

    /**
     * @brief Modulus operator.
     * @param other The object to perform the operation with.
     * @return Reference to the result.
     */
    virtual IObject& operator%(const IObject& other) const = 0;

    /**
     * @brief Bitwise AND operator.
     * @param other The object to perform the operation with.t      
     * @return Reference to the result.o     
     */   
    virtual IObject& operator&(const IObject& other) const = 0; 

    /**
     * @brief Bitwise OR operator.     
     * @param other The object to perform the operation with.     
     * @return Reference to the result.     
     */
    virtual IObject& operator|(const IObject& other) const = 0;

    /**      
     * @brief Bitwise XOR operator.     
     * @param other The object to perform the operation with.     
     * @return Reference to the result.     
     */
    virtual IObject& operator^(const IObject& other) const = 0;

    /**
     * @brief Bitwise left shift operator.
     * @param other The object to perform the operation with.
     * @return Reference to the result.
     */
    virtual IObject& operator<<(const IObject& other) const = 0;

    /**
     * @brief Bitwise right shift operator.
     * @param other The object to perform the operation with.
     * @return Reference to the result.
     */
    virtual IObject& operator>>(const IObject& other) const = 0;

    /**
     * @brief Modulus assignment operator.
     * @param other The object to perform the operation with.
     * @return Reference to the result.
     */
    virtual IObject& operator%=(const IObject& other) = 0;

    /**
     * @brief Bitwise AND assignment operator.
     * @param other The object to perform the operation with.
     * @return Reference to the result.
     */
    virtual IObject& operator&=(const IObject& other) = 0;

    /**
     * @brief Bitwise OR assignment operator.
     * @param other The object to perform the operation with.
     * @return Reference to the result.
     */
    virtual IObject& operator|=(const IObject& other) = 0;

    /**
     * @brief Bitwise XOR assignment operator.
     * @param other The object to perform the operation with.
     * @return Reference to the result.
     */
    virtual IObject& operator^=(const IObject& other) = 0;

    /**
     * @brief Bitwise left shift assignment operator.
     * @param other The object to perform the operation with.
     * @return Reference to the result.
     */
    virtual IObject& operator<<=(const IObject& other) = 0;

    /**
     * @brief Bitwise right shift assignment operator.
     * @param other The object to perform the operation with.
     * @return Reference to the result.
     */
    virtual IObject& operator>>=(const IObject& other) = 0;

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

/**
 * @file types.h
 * @brief Definition of the Rational class template.
 * @details This file defines the Rational class template, which represents a rational number.
 */
template<typename T>
class Rational final : public IObject {
public:
    /**
 * @brief Default constructor that initializes the rational number to 0/1.
 */
Rational();

/**
 * @brief Parameterized constructor that initializes the rational number with given numerator and denominator.
 * 
 * @param num The numerator of the rational number.
 * @param den The denominator of the rational number.
 */
Rational(T num, T den);

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
Rational(Rational&& other);
/**
 * @brief Assignment operator.
 * @param other The Rational object to copy from.
 * @return Reference to the assigned Rational object.
 */
Rational<T> &operator=(const Rational &other);

/**
 * @brief Destructor.
 */
~Rational();

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
 * @brief Post-increment operator.
 * 
 * @return The Rational object before incrementing.
 */
Rational operator++(int) override;

/**
 * @brief Pre-decrement operator.
 * 
 * @return Reference to the decremented Rational object.
 */
Rational& operator--() override;

/**
 * @brief Post-decrement operator.
 * 
 * @return The Rational object before decrementing.
 */
Rational operator--(int) override;

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
 * @param r The Rational object to write.
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
 * @file types.h
 * @brief Definition of the Vector class template.
 */

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
    Vector(size_t size);

    /**
     * @brief Move constructor.
     * 
     * @param other The vector to move from.
     */
    Vector(Vector&& other);

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
    Vector& operator++()requires Incrementable<T>  override;


    /** 
     * @brief Prefix decrement operator.
     * @return Reference to the decremented vector.     
     */    
    Vector& operator--()requires Incrementable<T>  override;    



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

/**
 * @brief Template class Matrix representing a matrix.
 * 
 * @tparam T Type of the elements in the matrix.
 */
template<typename T>
class Matrix final : public IObject {
public:
    /**
     * @brief Default constructor.
     */
    Matrix() {}

    /**
     * @brief Constructor that takes a vector of vectors.
     * 
     * @param vec Vector of vectors representing the rows of the matrix.
     */
    Matrix(const Vector<T>& vec);

    /**
     * @brief Move constructor.
     * 
     * @param other Another Matrix object to move.
     */
    Matrix(Matrix<T>&& other) {}

    /**
     * @brief Destructor.
     */
    ~Matrix() override {}

    /**
     * @brief Prints the contents of the matrix.
     */
    void print() const override {}

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
    const Matrix<T> &getData() const;

    /**
     * @brief Prefix increment operator.
     * @return Reference to the row at the specified index.
     * 
     */
    Matrix<T> &operator++() requires Incrementable<T> override;

    /**
     * @brief Prefix decrement operator.
     * @return Reference to the row at the specified index.
     */
    Matrix<T> &operator--() requires Incrementable<T> override;

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
            return os;
        }
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

/**
 * @class Rational
 * @brief A class representing rational numbers with a numerator and denominator.
 * 
 * The Rational class provides various arithmetic and bitwise operations for rational numbers.
 * It inherits from the IObject interface and overrides its virtual methods.
 */


#endif // TYPES_H

template<typename T>
Vector<T>::Vector(size_t size) {
    data.resize(size);
};

template<typename T>
Vector<T>::Vector(Vector&& other) {
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
bool Matrix<T>::operator==(const IObject& other) const {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        return data == otherMatrix->data;
    } else {
        return false;
    }
}
template<typename T>
bool Matrix<T>::operator!=(const IObject& other) const {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        return data != otherMatrix->data;
    } else {
        return true;
    }
}
template<typename T>
bool Matrix<T>::operator<(const IObject& other) const {
    if (const auto* otherMatrix = dynamic_cast<const Matrix<T>*>(&other)) {
        return data < otherMatrix->data;
    } else {
        return false;
    }
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
