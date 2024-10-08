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
#include "../include/core.h"
#include <cstring>  // Для strlen

ExpressionParser::ExpressionParser(std::string& intput) : input(intput), pos(0) {}

// If InterpreterError is not defined in errors.h, define it here
class InterpreterError : public std::runtime_error {
public:
    explicit InterpreterError(const std::string& message) : std::runtime_error(message) {}
};

std::vector<Token> ExpressionParser::parse(){
    std::vector<Token> tokens;

    Token token = nextToken();
    while(token.type != Token::End){
        tokens.push_back(token);
        token = nextToken();
    }
    return tokens;
}

Token ExpressionParser::nextToken(){
    while(pos < input.size() && std::isspace(input[pos])){
        ++pos;
    }

    if(pos == input.size()){
        return Token(Token::End,  "\0");
    }

    char current = input[pos];

    if (std::isdigit(current)) {
        std::string number;
        while (pos < input.size() && (std::isdigit(input[pos]) || input[pos] == '.')) {
            number += input[pos++];
        }
        return Token(Token::Number, number);
    }

    if (current == '+' || current == '-' || current == '*' || current == '/') {
        pos++;
        return Token(Token::Operator, std::string(1, current));
    }

    if (current == '(') {
        pos++;
        return Token(Token::LeftParen, "(");
    }

    if (current == ')') {
        pos++;
        return Token(Token::RightParen, ")");
    }

    throw InterpreterError("Unexpected character in input: " + std::string(1, current));
}