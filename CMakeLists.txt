cmake_minimum_required(VERSION 3.0)
project(mockqtimer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 5.14 REQUIRED COMPONENTS Core Test)

# Library
set(animals_MOC_HEADERS
        cow.hpp
        )

add_library(animals
        ${animals_MOC_HEADERS}
        cow.cpp
        )

target_link_libraries(animals PRIVATE
        Qt5::Core
        )

# Tests
set(animal_tests_MOC_HEADERS
        ${animals_MOC_HEADERS}
        animal_tests.hpp
        )

add_executable(animal_tests
        ${animal_tests_MOC_HEADERS}
        animal_tests.cpp
        )

add_test(NAME animal_tests COMMAND animal_tests)

target_link_libraries(animal_tests PRIVATE
        Qt5::Test
        Qt5::Core
        animals
        )