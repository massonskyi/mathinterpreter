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

// #include "include/imain.h"
// #include <iostream>

// int main(){
//     // ErrorHandler errorHandler;
//     // std::string inputs[] = {
//     //     "int a = 5;", // Корректный ввод
//     //     "int a = 5 + ;", // Синтаксическая ошибка
//     //     "float b = 3.14;", // Корректный ввод
//     //     "double c = 1.0 / 0;", // Деление на ноль
//     //     "char d = 'x';", // Корректный ввод
//     //     "int e = unknownVar;", // Неизвестная переменная
//     //     "int f = 5 + [3 * 2;", // Несоответствующие скобки
//     //     "int g = 5 + 3 * 2]",
//     //     "string g = \"ssadas\"" // Несоответствующие скобки
//     // };

//     //  std::string types[] = {
//     //     "Correct Input",
//     //     "Syntax Error",
//     //     "Correct Input",
//     //     "Division by Zero",
//     //     "Correct Input",
//     //     "Unknown Variable",
//     //     "Unmatched Bracket",
//     //     "Unmatched Bracket",
//     //     "Invalid Type"
//     // };

//     // for (size_t i = 0; i < sizeof(inputs) / sizeof(inputs[0]); ++i) {
//     //     std::cout << "Testing input: " << inputs[i] << std::endl;
//     //     errorHandler.handle(inputs[i], types[i]);
//     //     std::cout << std::endl;
//     // }

//     // return 0;
//         // Создаем объект интерпретатора
//     Interpreter interpreter;
//     std::string input;

//     while (true) {
//         std::cout << "Enter expression (or 'exit' to quit): ";
//         std::getline(std::cin, input);

//         if (input == "exit") {
//             break;
//         }

//         try {
//             auto result = interpreter.interpret(input);
//             std::cout << "Result: " << result << std::endl;
//         } catch (const std::exception& e) {
//             std::cerr << "Error: " << e.what() << std::endl;
//         }
//     }

//     return 0;
// }
#include "include/imain.h"
#include "core.h"
#include "interpreter.h"
#include "io.h"
#include <iostream>
#include <vector>

int main() {
    Interpreter interpreter;
    ConsoleIO consoleIO;
    FileIO fileIO;
    
    std::string mode;
    std::cout << "Выберите режим работы (console/file): ";
    std::cin >> mode;

    if (mode == "console") {
        consoleIO.open("console");
        consoleIO.read();

        while (consoleIO.isOpen()) {
            try {
                std::string input;
                std::cout << "Введите выражение (или 'exit' для выхода): ";
                std::getline(std::cin, input);
                
                if (input == "exit") {
                    break;
                }

                // Интерпретация выражения
                auto result = interpreter.interpret(input);

                // Вывод результата
                std::cout << "Результат: " << result.toString() << std::endl;
            } catch (const std::exception &e) {
                std::cerr << "Ошибка интерпретации: " << e.what() << std::endl;
            }
        }
        consoleIO.close();
    } else if (mode == "file") {
        std::string filename;
        std::cout << "Введите имя файла: ";
        std::cin >> filename;
        fileIO.open(filename);
        fileIO.read();

        while (fileIO.isOpen()) {
            try {
                std::string input;
                // Пример чтения файла (каждая строка — отдельное выражение)
                std::getline(std::cin, input); // Используйте fileIO.read() для чтения из файла

                if (input == "exit") {
                    break;
                }

                // Интерпретация выражения
                auto result = interpreter.interpret(input);

                // Вывод результата
                fileIO.write("Результат: " + result.toString() + "\n");
            } catch (const std::exception &e) {
                std::cerr << "Ошибка интерпретации: " << e.what() << std::endl;
            }
        }
        fileIO.close();
    }

    return 0;
}