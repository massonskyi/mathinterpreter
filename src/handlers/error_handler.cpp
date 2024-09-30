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
void ErrorHandler::handle(std::string& input, std::string& type) {
    std::string recommendation = get_recommendation(type);

    show_error_position(input);

    if (!recommendation.empty()) {
        char error_string[1024] = {0}, input_string[1024] = {0}, recommendation_string[1024] = {0};

        std::snprintf(error_string, sizeof(error_string), "Error: %s\n", type.c_str());
        std::snprintf(input_string, sizeof(input_string), "Input: %s\n", input.c_str());
        std::snprintf(recommendation_string, sizeof(recommendation_string), "Recommendation: %s\n", recommendation.c_str());

        out.err(error_string);
        out.info(input_string);
        out.warn(recommendation_string);
    }
}

std::string ErrorHandler::get_recommendation(const std::string& type) {
    if (type == "Syntax Error") {
        return "Проверьте расстановку скобок и операторов. Пример: \"int a = 5 + [2 * 3];\".";
    }
    if (type == "Unknown Variable") {
        return "Убедитесь, что переменная определена перед её использованием. Пример: \"int x; x = 5;\".";
    }
    if (type == "Invalid Operation") {
        return "Проверьте, поддерживается ли операция для указанных типов данных. Пример: \"int a = 5 / 0;\".";
    }
    if (type == "Division by Zero") {
        return "Нельзя делить на ноль. Исправьте знаменатель. Пример: \"double x = 1.0 / (a != 0 ? a : 1);\".";
    }
    if (type == "Unmatched Bracket") {
        return "Проверьте корректность закрытия скобок. Пример: \"int f = [5 + 3] * 2;\".";
    }
    if (type == "Invalid Type") {
        return "Недопустимый тип. Проверьте синтаксис и логику. Пример: \"int x = 5;\".";
    }
    return "Неизвестная ошибка. Проверьте синтаксис и логику программы.";
}
void ErrorHandler::show_error_position(std::string& input) {
    if (check_syntax_error(input)) {
        out.err("Syntax Error: Unmatched brackets\n");
        indicate_error_position(input);
    }

    if (input_checked_types(input)) {
        out.err("Invalid Type\n");
        indicate_error_position(input);
    }
}

bool ErrorHandler::check_syntax_error(std::string& input) {
    int open_bracket = 0;
    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] == '[') {
            open_bracket++;
        } else if (input[i] == ']') {
            open_bracket--;
        }
    }
    return open_bracket != 0;
}


void ErrorHandler::indicate_error_position(std::string& input) {
    char error_string[1024];
    int openBrackets = 0;
    for (size_t i = 0; i < input.size(); ++i) {
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
        std::snprintf(error_string, sizeof(error_string), "Error position: %zu (missing closing ']')\n", input.size() + 1);
        out.err(error_string);
        print_error_pointer(input, input.size());
    }
}

void ErrorHandler::print_error_pointer(std::string& input, size_t position) {
    std::string error_pointer(position, ' ');
    error_pointer += "^";
    out.err(error_pointer.c_str());
}

bool ErrorHandler::input_checked_types(std::string& input) {
    std::regex typeRegex("\\b(int|float|double|char|bool|string)\\b");
    std::smatch match;
    std::string inputString(input);

    while (std::regex_search(inputString, match, typeRegex)) {
        std::string type = match.str(0);
        if (type != "int" && type != "float" && type != "double" && type != "char" && type != "bool" && type != "string") {
            return true;
        }
        inputString = match.suffix().str();
    }

    return false;
}
