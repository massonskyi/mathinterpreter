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
#ifndef ERROR_HANDLER_H_
#define ERROR_HANDLER_H_

#include <string>
#include "output_handler.h"

/**
 * @class ErrorHandler
 * @brief A class to handle and report errors in input strings.
 * 
 * The ErrorHandler class provides methods to handle errors, check for syntax errors,
 * and indicate the position of errors in input strings.
 */
class ErrorHandler final {
public:
    /**
     * @brief Default constructor for ErrorHandler.
     */
    explicit ErrorHandler(bool enable_color=true);
    
    /**
     * @brief Virtual destructor for ErrorHandler.
     */
    ~ErrorHandler() = default;

    /**
     * @brief Handles the error based on the input and type.
     * 
     * @param input The input string where the error occurred.
     * @param type The type of error to handle.
     */
    void handle(std::string& input, std::string& type);
    /**
     * @brief Provides a recommendation based on the error type.
     * 
     * @param type The type of error.
     * @return A recommendation string for the given error type.
     */
    std::string get_recommendation(const std::string&  type);

    /** 
     * @brief Checks for syntax errors in the input string.(deprecated)
     * 
     * @param input The input string to check.
     * @return True if a syntax error is found, false otherwise.
     */
    bool check_syntax_error(std::string& input);
    
    /** 
     * @brief Checks for syntax errors in the input string.
     * 
     * @param input The input string to check.
     * @return True if a syntax error is found, false otherwise.
     */
    bool check_all_syntax_error(std::string&input);
    
    /** 
     * @brief Shows the position of the error in the input string.
     * 
     * @param input The input string where the error occurred.
     */
    void show_error_position(std::string& input);
    
    /**
     * @brief Indicates the position of the error in the input string.
     * 
     * @param input The input string where the error occurred.
     */
    void indicate_error_position(std::string&input);
    
    /** 
     * @brief Prints a pointer to the error position in the input string.
     * 
     * @param input The input string where the error occurred.
     * @param position The position of the error in the input string.
     */
    void print_error_pointer(std::string& input, size_t position);
    bool input_checked_types(std::string& input);

private:
    OutputHandler out; ///< The printer object for error handling.
};
#endif // ERROR_HANDLER_H_