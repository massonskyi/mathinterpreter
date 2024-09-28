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

#include <iostream>
#include <stdexcept>
#include <numeric> // For std::gcd

/**
 * @class Rational
 * @brief A class representing rational numbers with a numerator and denominator.
 *
 * The Rational class provides various arithmetic and comparison operations for rational numbers.
 */
template<typename T>
class Rational final {
public:
    /**
     * @brief Default constructor that initializes the rational number to 0/1.
     */
    Rational() : numerator(0), denominator(1) {}

    /**
     * @brief Parameterized constructor that initializes the rational number with given numerator and denominator.
     *
     * @param numerator The numerator of the rational number.
     * @param denominator The denominator of the rational number.
     */
    Rational(T numerator, T denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        this->numerator = numerator;
        this->denominator = denominator;
        _reduce();
    }

    /**
     * @brief Copy constructor.
     *
     * @param other The Rational object to copy from.
     */
    Rational(const Rational& other) : numerator(other.numerator), denominator(other.denominator) {}

    /**
     * @brief Move constructor.
     *
     * @param other The Rational object to move from.
     */
    Rational(Rational&& other) noexcept : numerator(other.numerator), denominator(other.denominator) {
        other.numerator = 0;
        other.denominator = 1;
    }

    /**
     * @brief Assignment operator.
     * @param other The Rational object to copy from.
     * @return Reference to the assigned Rational object.
     */
    Rational& operator=(const Rational& other) {
        if (this != &other) {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }

    /**
     * @brief Move assignment operator.
     * @param other The Rational object to move from.
     * @return Reference to the assigned Rational object.
     */
    Rational& operator=(Rational&& other) noexcept {
        if (this != &other) {
            numerator = other.numerator;
            denominator = other.denominator;
            other.numerator = 0;
            other.denominator = 1;
        }
        return *this;
    }

    /**
     * @brief Get the numerator of the rational number.
     * @return The numerator.
     */
    T getNumerator() const { return numerator; }

    /**
     * @brief Get the denominator of the rational number.
     * @return The denominator.
     */
    T getDenominator() const { return denominator; }

    // Arithmetic operators
    Rational operator+(const Rational& other) const {
        return Rational(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    Rational operator-(const Rational& other) const {
        return Rational(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    Rational operator*(const Rational& other) const {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    Rational operator/(const Rational& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Division by zero.");
        }
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    // Comparison operators
    bool operator==(const Rational& other) const {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    bool operator<(const Rational& other) const {
        return (numerator * other.denominator < other.numerator * denominator);
    }

    bool operator>(const Rational& other) const {
        return (numerator * other.denominator > other.numerator * denominator);
    }

    bool operator<=(const Rational& other) const {
        return !(*this > other);
    }

    bool operator>=(const Rational& other) const {
        return !(*this < other);
    }

    // Stream operators
    friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
        os << r.numerator << "/" << r.denominator;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Rational& r) {
        char slash; // To consume the '/' character
        is >> r.numerator >> slash >> r.denominator;
        if (r.denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        r._reduce(); // Simplify after input
        return is;
    }

private:
    T numerator; // Numerator of the rational number
    T denominator; // Denominator of the rational number

    /**
     * @brief Reduces the rational number to its simplest form.
     */
    void _reduce() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        T gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }
};

#endif // RATIONAL_H
