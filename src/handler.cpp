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

#include "../include/handler.h"


#include <iostream>
#include <vector>
#include <regex>
#include <format>
#include <string.h>

ColorPrettyPrinter::ColorPrettyPrinter(bool enable_color): color_enabled(enable_color) {};

void ColorPrettyPrinter::set_color_enabled(bool enabled) {
    color_enabled = enabled;
};

void ColorPrettyPrinter::set_custom_color(Color color, int ansiCode) {
    custom_color[static_cast<int>(color)] = ansiCode;
};

void ColorPrettyPrinter::set_global_format(const char* format) {
    global_format = format;
};

void ColorPrettyPrinter::err(const char* text) const {
    print(text, Color::Red);
};

void ColorPrettyPrinter::debug(const char* text) const {
    print(text, Color::Green);
};

void ColorPrettyPrinter::info(const char* text) const {
    print(text, Color::Blue);
};

void ColorPrettyPrinter::warn(const char* text) const {
    print(text, Color::Yellow);
};

void ColorPrettyPrinter::success(const char* text) const {
    print(text, Color::Green);
};

void ColorPrettyPrinter::critical(const char* text) const {
    print(text, Color::Red);
};

void ColorPrettyPrinter::fatal(const char* text) const {
    print(text, Color::Red);
};

void ColorPrettyPrinter::trace(const char* text) const {
    print(text, Color::Cyan);
};

void ColorPrettyPrinter::print(const char* text, Color color) const {
    if (color_enabled) {
        if (custom_color[static_cast<int>(color)]) {
            std::cout << "\033[" << custom_color[static_cast<int>(color)].value() << "m";
        } else {
            std::cout << "\033[" << static_cast<int>(color) << "m";
        }
    }
    if (global_format) {
        char buffer[1024];
        std::snprintf(buffer, sizeof(buffer), global_format.value(), text);
        std::cout << buffer;
    } else {
        std::cout << text;
    }
    if (color_enabled) {
        std::cout << "\033[0m";
    }
};

template<typename... Args>
void ColorPrettyPrinter::formatted(Color color, const char* formatString, Args&&... args) const {
    char formattedMessage[1024];
    std::snprintf(formattedMessage, sizeof(formattedMessage), formatString, std::forward<Args>(args)...);
    
    // Если установлен глобальный формат, используем его
    if (global_format.has_value()) {
        char globalFormattedMessage[1024];
        std::snprintf(globalFormattedMessage, sizeof(globalFormattedMessage), global_format.value(), formattedMessage);
        print(globalFormattedMessage, color);
    } else {
        print(formattedMessage, color);
    }
};

ErrorHandler::ErrorHandler(bool enable_color): printer(enable_color) {};


void ErrorHandler::handle(const char* input, const char* type){
    const char *recommendation = get_recommendation(type);

    show_error_position(input);

    if (recommendation != nullptr) {
        char error_string[1024], intput_string[1024], recommendation_string[1024];

        std::snprintf(error_string, sizeof(error_string), "Error: %s\n", type);
        std::snprintf(intput_string, sizeof(intput_string), "Input: %s\n", input);
        std::snprintf(recommendation_string, sizeof(recommendation_string), "Recommendation: %s\n", recommendation);

        printer.err(error_string);
        printer.info(intput_string);
        printer.warn(recommendation_string);
    }
};

const char* ErrorHandler::get_recommendation(const char* type){
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
    return "Unknown error. Check the syntax and logic.";

};

void ErrorHandler::show_error_position(const char* input){
    if (check_syntax_error(input)){
        printer.err("Syntax Error: Unmatched brackets");
        printer.err("Check the expression for mismatched brackets.\n");
        indicate_error_position(input);
    }
};

// [[deprecated("Use all_syntax_error v2 instead")]]
bool ErrorHandler::check_syntax_error(const char* input){
//     std::vector<char> stack;
//     for (size_t i = 0; i < strlen(input); i++) {
//         if (input[i] == '(') {
//             stack.push_back('(');
//         } else if (input[i] == ')') {
//             if (stack.empty()) {
//                 return true;
//             }
//             stack.pop_back();
//         }
//     }
//     return !stack.empty();

    int open_bracket = 0;
    for (size_t i = 0; i < strlen(input); i++) {
        if (input[i] == '[') {
            open_bracket++;
        } else if (input[i] == ']') {
            open_bracket--;
        }
    }

    return open_bracket != 0;
};
[[deprecated("Use indicate_error_position v2 instead")]]
void ErrorHandler::indicate_error_position(const char* input){
    std::string error_pointer;
    for (size_t i = 0; i < strlen(input); i++) {
        if (input[i] == '(' || input[i] == ')') {
            error_pointer += "^";
        } else {
            error_pointer += " ";
        }
    }
    printer.err(error_pointer.c_str());
};

void ErrorHandler::indicate_error_position_v2(const char* input){
    int openBrackets = 0;
    for (size_t i = 0; i < strlen(input); ++i) {
        if (input[i] == '[') openBrackets++;
        if (input[i] == ']') openBrackets--;
        // Если встретили закрывающую скобку, а открывающих не осталось
        if (openBrackets < 0) {
            std::cerr << "Error position: " << i + 1 << " (unexpected ']')\n";
            print_error_pointer(input, i);
            return;
        }
    }
    // Если остались открывающие скобки
    if (openBrackets > 0) {
        std::cerr << "Error position: " << strlen(input) + 1 << " (missing closing ']')\n";
        print_error_pointer(input, strlen(input));
    }
};

void ErrorHandler::print_error_pointer(const char* input, size_t position){
    std::string error_pointer;
    for (size_t i = 0; i < position; i++) {
        error_pointer += " ";
    }
    error_pointer += "^";
    printer.err(error_pointer.c_str());

    /* or */
    // {
    //     std::cerr << input << "\n";
    //     for (size_t i = 0; i < position; ++i) {
    //         std::cerr << " ";
    //     }
    //     std::cerr << "^\n";
    // }
};