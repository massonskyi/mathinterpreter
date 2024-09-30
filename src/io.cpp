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

#include <iostream>
#include <fstream>
#include <string>

class IO {
public:
    virtual void read() = 0;
    virtual void write(const std::string &data) = 0;
    virtual void open(const std::string &source) = 0;
    virtual void close() = 0;
    virtual bool isOpen() const = 0;

protected:
    std::string source;
    bool openFlag = false;
};

class ConsoleIO final : public IO {
public:
    void read() override {
        std::cout << "Введите данные через консоль:\n";
    }

    void write(const std::string &data) override {
        std::cout << data;
    }

    void open(const std::string &source) override {
        std::cout << "Открытие консоли для ввода/вывода.\n";
        openFlag = true;
    }

    void close() override {
        std::cout << "Закрытие консоли.\n";
        openFlag = false;
    }

    bool isOpen() const override {
        return openFlag;
    }
};

class FileIO final : public IO {
public:
    void read() override {
        std::ifstream file(source);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::cout << "Чтение из файла: " << line << std::endl;
            }
            file.close();
        } else {
            std::cerr << "Не удалось открыть файл для чтения.\n";
        }
    }

    void write(const std::string &data) override {
        std::ofstream file(source, std::ios::app);
        if (file.is_open()) {
            file << data;
            file.close();
        } else {
            std::cerr << "Не удалось открыть файл для записи.\n";
        }
    }

    void open(const std::string &source) override {
        this->source = source;
        openFlag = true;
    }

    void close() override {
        openFlag = false;
    }

    bool isOpen() const override {
        return openFlag;
    }
};

#endif // _IO_H_
