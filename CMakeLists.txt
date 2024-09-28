cmake_minimum_required(VERSION 3.10)
project(MathInterpreter)

# Устанавливаем стандарт C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем путь к заголовочным файлам
include_directories(${CMAKE_SOURCE_DIR}/include)

# Файлы с исходным кодом
set(SOURCES
        src/mod/objects.c
        src/core.cpp
        src/io.cpp
        src/handlers/output_handler.cpp
        src/handlers/error_handler.cpp
        main.cpp
)

# Добавляем исполняемый файл
add_executable(math_interpreter ${SOURCES})

# Для тестирования: Создаем отдельные исполняемые файлы для каждого теста
# Включаем тесты, если CMake будет вызван с флагом -DBUILD_TESTS=ON
option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    # Create test executables
    add_executable(test_vector tests/vector_test.cpp include/types/vector.hpp)
    add_executable(test_matrix tests/matrix_test.cpp include/types/matrix.hpp)
    add_executable(test_rational tests/rational_test.cpp include/types/rational.hpp)
    add_executable(test_interpreter tests/interpreter_test.cpp src/core.cpp)

    # Link test executables with Google Test libraries
    target_link_libraries(test_vector GTest::GTest GTest::Main)
    target_link_libraries(test_matrix GTest::GTest GTest::Main)
    target_link_libraries(test_rational GTest::GTest GTest::Main)
    target_link_libraries(test_interpreter GTest::GTest GTest::Main)

    add_test(NAME TestVector COMMAND test_vector)
    add_test(NAME TestMatrix COMMAND test_matrix)
    add_test(NAME TestRational COMMAND test_rational)
    add_test(NAME TestInterpreter COMMAND test_interpreter)
endif()

# Сообщаем, что мы находимся в режиме отладки, если установлен соответствующий флаг
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Build type: Debug")
endif()
