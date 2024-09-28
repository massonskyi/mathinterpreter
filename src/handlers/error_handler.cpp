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


#include "../../include/handlers/error_handler.h"
#include <iostream>
#include <vector>
#include <regex>
#include <format>
#include <string.h>

ErrorHandler::ErrorHandler(bool enable_color) : out(enable_color) {}
void ErrorHandler::handle(const char* input, const char* type) {
    const char* recommendation = get_recommendation(type);

    show_error_position(input);

    if (recommendation != nullptr) {
        char error_string[1024], input_string[1024], recommendation_string[1024];

        std::snprintf(error_string, sizeof(error_string), "Error: %s\n", type);
        std::snprintf(input_string, sizeof(input_string), "Input: %s\n", input);
        std::snprintf(recommendation_string, sizeof(recommendation_string), "Recommendation: %s\n", recommendation);

        out.err(error_string);
        out.info(input_string);
        out.warn(recommendation_string);
    }
}

const char* ErrorHandler::get_recommendation(const char* type) {
    if (strcmp(type, "Syntax Error") == 0) {
        return "Check if all brackets and operators are placed correctly.";
    }
    if (strcmp(type, "Unknown Variable") == 0) {
        return "Ensure that the variable is defined before it is used.";
    }
    if (strcmp(type, "Invalid Operation") == 0) {
        return "Check if the operation is supported for the given data types.";
    }
    if (strcmp(type, "Division by Zero") == 0) {
        return "Rational numbers cannot be divided by zero. Correct the denominator.";
    }
    if (strcmp(type, "Unmatched Bracket") == 0) {
        return "Ensure all brackets are closed properly.";
    }
    if (strcmp(type, "Invalid Type") == 0) {
        return "Invalid type. Check the syntax and logic.";
    }
    return "Unknown error. Check the syntax and logic.";
}

void ErrorHandler::show_error_position(const char* input) {
    if (check_syntax_error(input)) {
        out.err("Syntax Error: Unmatched brackets\n");
        indicate_error_position(input);
    }

    if (input_checked_types(input)) {
        out.err("Invalid Type\n");
        indicate_error_position(input);
    }
}

bool ErrorHandler::check_syntax_error(const char* input) {
    int open_bracket = 0;
    for (size_t i = 0; i < strlen(input); i++) {
        if (input[i] == '[') {
            open_bracket++;
        } else if (input[i] == ']') {
            open_bracket--;
        }
    }
    return open_bracket != 0;
}


void ErrorHandler::indicate_error_position(const char* input) {
    char error_string[1024];
    int openBrackets = 0;
    for (size_t i = 0; i < strlen(input); ++i) {
        if (input[i] == '[') openBrackets++;
        if (input[i] == ']') openBrackets--;
        if (openBrackets < 0) {
            std::snprintf(error_string, sizeof(error_string), "Error position: %zu (unexpected ']')\n", i + 1);
            out.err(error_string);
            print_error_pointer(input, i);
            return;
        }
    }
    if (openBrackets > 0) {
        std::snprintf(error_string, sizeof(error_string), "Error position: %zu (missing closing ']')\n", strlen(input) + 1);
        out.err(error_string);
        print_error_pointer(input, strlen(input));
    }
}

void ErrorHandler::print_error_pointer(const char* input, size_t position) {
    std::string error_pointer(position, ' ');
    error_pointer += "^";
    out.err(error_pointer.c_str());
}

bool ErrorHandler::input_checked_types(const char* input) {
    std::regex typeRegex("\\b(int|float)\\b");
    std::smatch match;
    std::string inputString(input);

    while (std::regex_search(inputString, match, typeRegex)) {
        std::string type = match.str(0);
        if (type != "int" && type != "float" && type != "double" && type != "char") {
            return true;
        }
        inputString = match.suffix().str();
    }

    return false;
}

