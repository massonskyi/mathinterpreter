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

#ifndef _IO_H_
#define _IO_H_

#include <string>

/**
 * @class IO
 * @brief Abstract base class for input/output operations.
 *
 * The IO class provides an interface for reading from, writing to, opening, and closing an input/output source.
 * Derived classes must implement all pure virtual functions to handle specific input/output mechanisms.
 *
 * @note This class cannot be instantiated directly.
 *
 * @var IO::source
 * The source to be used for input/output operations.
 *
 * @var IO::openFlag
 * A flag indicating whether the input/output source is open.
 * 
 * This class provides an interface for reading and writing data,
 * as well as managing the state of the input/output source.
 */
class IO {
public:
/**
 * @brief Reads data from the source.
 *
 * This is a pure virtual function that must be implemented by derived classes.
 */
virtual void read() = 0;

/**
 * @brief Writes data to the source.
 *
 * @param data The data to be written.
 *
 * This is a pure virtual function that must be implemented by derived classes.
 */
virtual void write(const std::string &data) = 0;

/**
 * @brief Opens the input/output source.
 *
 * @param source The source to be opened.
 *
 * This is a pure virtual function that must be implemented by derived classes.
 */
virtual void open(const std::string &source) = 0;

/**
 * @brief Closes the input/output source.
 *
 * This is a pure virtual function that must be implemented by derived classes.
 */
virtual void close() = 0;

/**
 * @brief Checks if the input/output source is open.
 *
 * @return true if the source is open, false otherwise.
 *
 * This is a pure virtual function that must be implemented by derived classes.
 */
virtual bool isOpen() const = 0;

protected:
    std::string source;
    bool openFlag = false;
};

/**
 * @class ConsoleIO

 * @brief A final class for console input/output operations.
 * 
 * This class provides methods to read from and write to the console,
 * as well as to open and close the console stream.
 */
class ConsoleIO final : public IO { 
public:
    /**
     * @brief Reads data from the console.
     * 
     * This method overrides the read function from the IO base class.
     */
    void read() override;

    /**
     * @brief Writes data to the console.
     * 
     * @param data The string data to be written to the console.
     * 
     * This method overrides the write function from the IO base class.
     */
    void write(const std::string &data) override;

    /**
     * @brief Opens the console stream.
     * 
     * @param source The source to open (not typically used for console IO).
     * 
     * This method overrides the open function from the IO base class.
     */
    void open(const std::string &source) override;

    /**
     * @brief Closes the console stream.
     * 
     * This method overrides the close function from the IO base class.
     */
    void close() override;

    /**
     * @brief Checks if the console stream is open.
     * 
     * @return true if the console stream is open, false otherwise.
     * 
     * This method overrides the isOpen function from the IO base class.
     */
    bool isOpen() const override;

protected:
    /** 
     * @brief Method run to execute code for console IO.
     * @param args The arguments to be passed to the run method.
     * @return Nothing.
    */
    void run();

private:
    bool openFlag = false;
    std::string source = "console";
};

class FileIO final : public IO {
public:
    /**
     * @brief Reads data from the console.
     * 
     * This method overrides the read function from the IO base class.
     */
    void read() override;

    /**
     * @brief Writes data to the console.
     * 
     * @param data The string data to be written to the console.
     * 
     * This method overrides the write function from the IO base class.
     */
    void write(const std::string &data) override;

    /**
     * @brief Opens the console stream.
     * 
     * @param source The source to open (not typically used for console IO).
     * 
     * This method overrides the open function from the IO base class.
     */
    void open(const std::string &source) override;

    /**
     * @brief Closes the console stream.
     * 
     * This method overrides the close function from the IO base class.
     */
    void close() override;

    /**
     * @brief Checks if the console stream is open.
     * 
     * @return true if the console stream is open, false otherwise.
     * 
     * This method overrides the isOpen function from the IO base class.
     */
    bool isOpen() const override;

protected:
    /** 
     * @brief Method run to execute code for file IO.
     * @param args The arguments to be passed to the run method.
     * @return Nothing.
    */
    void run();

private:
    bool openFlag = false;
    std::string source = "file";
};

#endif // _IO_H_