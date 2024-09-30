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

#ifndef __CORE_H__
#define __CORE_H__

#include <vector>
#include <memory>
#include "handlers/error_handler.h"
#include "types/types.h"

using Number = float;

/**
 * @brief Token is type of token

 */
struct Token{
    enum Type{
        Number,
        Operator,
        LeftParen,
        RightParen,
        End
    }type;
    std::string value;

    Token(Type t, std::string v): type(t), value(v) {}
};



class ExpressionParser{
public:
    ExpressionParser() = default;
    explicit ExpressionParser(std::string &input);

    std::vector<Token> parse();
private:
    std::string input;
    size_t pos;
    
    Token nextToken();
};



class Evaluator{
public:
    Evaluator() = default;
    explicit Evaluator(const std::vector<Token>& tokens);
    Number evaluate();
    

    template<typename _Tp>
    Vector<_Tp> evaluateVector();

    template<typename _Tp>
    Matrix<_Tp> evaluateMatrix();

    template<typename _Tp>
    Rational<_Tp> evaluateRational();

private:

    std::vector<Token> tokens;
    size_t pos;

    Number parseExpression();
    Number parseTerm();
    Number parseFactor();

};
#endif // __CORE_H__