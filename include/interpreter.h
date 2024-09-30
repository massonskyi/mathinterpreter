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
#pragma once
#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__
#include "core.h"
#include <sstream> // Для std::stringstream
#include <stdexcept> // Для std::invalid_argument
#include <string> // Для std::string
class Interpreter{
public:
    Interpreter();

    Number interpret(std::string& expression);
    

    // Реализация шаблонной функции для векторов
    template<typename _Tp>
    Vector<_Tp> interpretVector(const std::string& expression) {
        std::stringstream ss(expression);
        char temp;
        ss >> temp; // Ожидаем '['
        
        if (temp != '[') {
            throw std::invalid_argument("Invalid vector format");
        }

        Vector<_Tp> result;
        _Tp value;
        
        while (ss >> value) {
            result.push_back(value);
            ss >> temp; // Считываем разделитель или закрывающую скобку ']'
            if (temp == ']') {
                break;
            }
        }

        if (temp != ']') {
            throw std::invalid_argument("Invalid vector format");
        }

        return result;
    }


    // Реализация шаблонной функции для матриц
    template<typename _Tp>
    Matrix<_Tp> interpretMatrix(const std::string& expression) {
        std::stringstream ss(expression);
        char temp;
        ss >> temp; // Ожидаем '['
        
        if (temp != '[') {
            throw std::invalid_argument("Invalid matrix format");
        }

        Matrix<_Tp> result;
        std::vector<_Tp> row;
        _Tp value;

        while (ss >> value) {
            row.push_back(value);
            ss >> temp; // Считываем разделитель (например, пробел или ';')
            if (temp == ';') {
                result.push_back(row);
                row.clear();
            } else if (temp == ']') {
                result.push_back(row);
                break;
            }
        }

        if (temp != ']') {
            throw std::invalid_argument("Invalid matrix format");
        }

        return result;
    }

    // Реализация шаблонной функции для рациональных чисел
    template<typename _Tp>
    Rational<_Tp> interpretRational(const std::string& expression) {
        std::stringstream ss(expression);
        _Tp numerator, denominator;
        char slash;

        ss >> numerator >> slash >> denominator;
        
        if (slash != '/' || denominator == 0) {
            throw std::invalid_argument("Invalid rational number format or division by zero");
        }

        return Rational(numerator, denominator);
    }

private:
    std::shared_ptr<ErrorHandler> errorHandler;
};

#endif // __INTERPRETER_H__