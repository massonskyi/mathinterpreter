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

#ifndef OUTPUT_HANDLER_H_
#define OUTPUT_HANDLER_H_

#include <optional>
#include <array>
/**
 * @class OutputHandler
 * @brief A class for printing text with ANSI color codes.
 * 
 * This class provides functionality to print text with various ANSI color codes.
 * It supports enabling/disabling color output, setting custom colors, and global formatting.
 */
class OutputHandler final{
public:
    /**    
     * @enum Color
     * @brief Enumeration of ANSI color codes.
     * 
     * This enum defines various ANSI color codes that can be used for text formatting.
     */
    enum class Color {
        Reset = 0,   ///< Reset color to default.
        Red = 31,    ///< Red color.
        Green = 32,  ///< Green color.
        Yellow = 33, ///< Yellow color.
        Blue = 34,   ///< Blue color.
        Magenta = 35,///< Magenta color.
        Cyan = 36,   ///< Cyan color.
        White = 37   ///< White color.
    };
    /**
     * @brief Constructor for OutputHandler.
     * 
     * @param enable_color A boolean to enable or disable color output. Default is true.
     * @param global_format The format string to use globally.
     */
    explicit OutputHandler(bool enable_color = true, std::optional<const char*> global_format = std::nullopt);

    /**
     * @brief Set whether color output is enabled.
     * 
     * @param enabled A boolean to enable or disable color output.
     */
    void set_color_enabled(bool enabled);

    /**
     * @brief Set a custom color with a specific ANSI code.
     * 
     * @param color The color to set.
     * @param code The ANSI code for the custom color.
     */
    void set_custom_color(Color color, const char* code);

    /**
     * @brief Set a global format for all printed text.
     * 
     * @param format The format string to use globally.
     */
    void set_global_format(const char* format);

    /**
     * @brief Print text with a specified color.
     * 
     * @param text The text to print.
     * @param color The color to use for the text. Default is Color::Reset.
     */
    void print(const char* text, Color color = Color::Reset) const;
    /**
     * @brief Print an error message with red text.
     * 
     * @param text The error message to print.
     */
    void err(const char* text) const;

    /**
     * @brief Print formatted text with a specified color.
     * 
     * @param text The text to print.
     */
    void debug(const char* text) const;

    /**
     * @brief Print formatted text with a specified color.
     * 
     * @param text The text to print.
     */
    void info(const char* text) const;

    /**
     * @brief Print formatted text with a specified color.
     * 
     * @param text The text to print.
     */
    void warn(const char* text) const;

    /**
     * @brief Print formatted text with a specified color.
     * 
     * @param text The text to print.
     */
    void success(const char* text) const;

    /**
     * @brief Print formatted text with a specified color.
     * 
     * @param text The text to print.
     */
    void critical(const char* text) const;

    /**
     * @brief Print formatted text with a specified color.
     * 
     * @param text The text to print.
     */
    void fatal(const char* text) const;

    /**
     * @brief Print formatted text with a specified color.
     * 
     * @param text The text to print.
     */
    void trace(const char* text) const;

    /**
     * @brief Print formatted text with a specified color.
     * 
     * @tparam Args Variadic template for format arguments.
     * @param color The color to use for the text.
     * @param formatString The format string.
     * @param args The arguments for the format string.
     */
    template<typename... Args>
    void formatted(Color color, const char* formatString, Args&&... args) const;
    
private:
    bool color_enabled; ///< Boolean indicating if color output is enabled.    
    std::optional<const char*> global_format; ///< Optional global format string.
    std::array<std::optional<const char*>, 256> custom_color; ///< Array of optional custom ANSI codes for colors.
};
#endif // OUTPUT_HANDLER_H_