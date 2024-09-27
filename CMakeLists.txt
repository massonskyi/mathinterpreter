#  COPYRIGHT (c) 2024 Massonskyi
#  All rights reserved.
#  
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions are met:
#  
#   1. Redistributions of source code must retain the above copyright notice,
#      this list of conditions and the following disclaimer.
#   2. Redistributions in binary form must reproduce the above copyright notice,
#      this list of conditions and the following disclaimer in the documentation
#      and/or other materials provided with the distribution.
#   3. Neither the name of the copyright holder nor the names of its contributors
#      may be used to endorse or promote products derived from this software
#      without specific prior written permission.
#  
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
#   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
#   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
#   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
#   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
#   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
#   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
#   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
#   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#   POSSIBILITY OF SUCH DAMAGE.
#  
cmake_minimum_required(VERSION 3.10)
project(MathInterpreter)

# Устанавливаем стандарт C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Добавляем путь к заголовочным файлам
include_directories(${CMAKE_SOURCE_DIR}/include)

# Файлы с исходным кодом
set(SOURCES
    src/mod/objects.cpp
    src/core.cpp
    src/io.cpp
    src/handler.cpp
    main.cpp
)

# Добавляем исполняемый файл
add_executable(math_interpreter ${SOURCES})

# Для тестирования: Создаем отдельные исполняемые файлы для каждого теста
# Включаем тесты, если CMake будет вызван с флагом -DBUILD_TESTS=ON
option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    enable_testing()
    add_executable(test_vector tests/vector_test.cpp src/types.hpp)
    add_executable(test_matrix tests/matrix_test.cpp src/types.hpp)
    add_executable(test_rational tests/rational_test.cpp src/types.hpp)
    add_executable(test_interpreter tests/interpreter_test.cpp src/core.cpp)

    # Добавляем команды для запуска тестов
    add_test(NAME TestVector COMMAND test_vector)
    add_test(NAME TestMatrix COMMAND test_matrix)
    add_test(NAME TestRational COMMAND test_rational)
    add_test(NAME TestInterpreter COMMAND test_interpreter)
endif()

# Сообщаем, что мы находимся в режиме отладки, если установлен соответствующий флаг
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Build type: Debug")
endif()
