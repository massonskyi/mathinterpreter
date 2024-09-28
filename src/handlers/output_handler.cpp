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
#include "../../include/handlers/output_handler.h"
#include <iostream>

OutputHandler::OutputHandler(bool enable_color, std::optional<const char*> global_format)
: color_enabled(enable_color), global_format(global_format) {
    custom_color.fill(std::nullopt); ///<- Initialization array custom_color
};

void OutputHandler::set_color_enabled(bool enabled) {
    color_enabled = enabled;
};

void OutputHandler::set_custom_color(Color color, const char* code) {
    custom_color[static_cast<int>(color)] = code;
};

void OutputHandler::set_global_format(const char* format) {
    global_format = format;
};

void OutputHandler::err(const char* text) const {
    print(text, Color::Red);
};

void OutputHandler::debug(const char* text) const {
    print(text, Color::Green);
};

void OutputHandler::info(const char* text) const {
    print(text, Color::Blue);
};

void OutputHandler::warn(const char* text) const {
    print(text, Color::Yellow);
};

void OutputHandler::success(const char* text) const {
    print(text, Color::Green);
};

void OutputHandler::critical(const char* text) const {
    print(text, Color::Red);
};

void OutputHandler::fatal(const char* text) const {
    print(text, Color::Red);
};

void OutputHandler::trace(const char* text) const {
    print(text, Color::Cyan);
};

void OutputHandler::print(const char* text, Color color) const {
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
void OutputHandler::formatted(Color color, const char* formatString, Args&&... args) const {
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
