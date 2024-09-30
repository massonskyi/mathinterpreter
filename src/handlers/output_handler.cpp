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
#include <sstream>
#include <format>

OutputHandler::OutputHandler(bool enable_color, std::optional<std::string> global_format)
: color_enabled(enable_color), global_format(global_format) {
    custom_color.fill(std::nullopt); ///<- Initialization array custom_color
};

void OutputHandler::set_color_enabled(bool enabled) {
    color_enabled = enabled;
};

void OutputHandler::set_custom_color(Color color, std::string code) {
    custom_color[static_cast<int>(color)] = code;
};

void OutputHandler::set_global_format(std::string format) {
    global_format = format;
};

void OutputHandler::err(std::string text) const {
    print(text, Color::Red);
};

void OutputHandler::debug(std::string text) const {
    print(text, Color::Green);
};

void OutputHandler::info(std::string text) const {
    print(text, Color::Blue);
};

void OutputHandler::warn(std::string text) const {
    print(text, Color::Yellow);
};

void OutputHandler::success(std::string text) const {
    print(text, Color::Green);
};

void OutputHandler::critical(std::string text) const {
    print(text, Color::Red);
};

void OutputHandler::fatal(std::string text) const {
    print(text, Color::Red);
};

void OutputHandler::trace(std::string text) const {
    print(text, Color::Cyan);
};

void OutputHandler::print(std::string text, Color color) const {
    if (color_enabled) {
        if (custom_color[static_cast<int>(color)]) {
            std::cout << "\033[" << custom_color[static_cast<int>(color)].value() << "m";
        } else {
            std::cout << "\033[" << static_cast<int>(color) << "m";
        }
    }
    if (global_format) {
        std::ostringstream oss;
        oss << global_format.value();
        std::string formatted_text = oss.str();
        std::cout << formatted_text;
    } else {
        std::cout << text;
    }
    if (color_enabled) {
        std::cout << "\033[0m";
    }
};

template<typename... Args>
void OutputHandler::formatted(Color color, std::string formatString, Args&&... args) const {
    std::string formattedMessage = std::format(formatString, std::forward<Args>(args)...);
    
    if (global_format.has_value()) {
        std::ostringstream global_oss;
        global_oss << std::format(global_format.value(), formattedMessage);
        std::string globalFormattedMessage = global_oss.str();
        print(globalFormattedMessage, color);
    } else {
        print(formattedMessage, color);
    }
};
