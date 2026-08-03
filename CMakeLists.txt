cmake_minimum_required(VERSION 3.31)
project(DSA_C C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_compile_options(-Wall -Wextra -Wpedantic)

find_program(CLANG_TIDY clang-tidy)
if(CLANG_TIDY)
    set(CMAKE_C_CLANG_TIDY
        clang-tidy
        --checks=*,-llvmlibc-*,-altera-*,-modernize-*,-hicpp-*,-cppcoreguidelines-*,-llvm-header-guard,-readability-magic-numbers,-bugprone-easily-swappable-parameters
        --extra-arg=-std=c23
    )
endif()

find_program(CPPCHECK cppcheck)
if(CPPCHECK)
    set(CMAKE_C_CPPCHECK
        cppcheck
        --enable=all
        --inconclusive
        --std=c23
        --suppress=missingIncludeSystem
        --suppress=unusedFunction
        --suppress=staticFunction
    )
endif()

# Linked List
add_library(linked_list linked_list/linked_list.c)
target_include_directories(linked_list PUBLIC linked_list)
add_executable(linked_list_example linked_list/examples/linked_list_example.c)
target_link_libraries(linked_list_example linked_list)
