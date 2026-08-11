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
        --checks=*,-llvmlibc-*,-altera-*,-modernize-*,-hicpp-*,-cppcoreguidelines-*,-llvm-header-guard,-readability-magic-numbers,-bugprone-easily-swappable-parameters,-misc-no-recursion
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

find_program(CLANG_FORMAT clang-format)
if(CLANG_FORMAT)
    file(GLOB_RECURSE ALL_SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/*.c
        ${CMAKE_SOURCE_DIR}/*.h
    )
    list(FILTER ALL_SOURCE_FILES EXCLUDE REGEX "${CMAKE_BINARY_DIR}/.*")
    add_custom_target(format_check ALL
        COMMAND ${CLANG_FORMAT} --dry-run --Werror ${ALL_SOURCE_FILES}
        COMMENT "Checking formatting..."
    )
endif()

# Linked List
add_library(linked_list linked_list/linked_list.c)
target_include_directories(linked_list PUBLIC linked_list)
add_executable(linked_list_example linked_list/examples/linked_list_example.c)
target_link_libraries(linked_list_example linked_list)

# Doubly Linked List
add_library(doubly_linked_list doubly_linked_list/doubly_linked_list.c)
target_include_directories(doubly_linked_list PUBLIC doubly_linked_list)
add_executable(doubly_linked_list_example doubly_linked_list/examples/doubly_linked_list_example.c)
target_link_libraries(doubly_linked_list_example doubly_linked_list)

# Stack (array based)
add_library(stack_array stack/stack_array.c)
target_include_directories(stack_array PUBLIC stack)
add_executable(stack_array_example stack/examples/stack_array_example.c)
target_link_libraries(stack_array_example stack_array)

# Stack (list based)
add_library(stack_list stack/stack_list.c)
target_include_directories(stack_list PUBLIC stack)
add_executable(stack_list_example stack/examples/stack_list_example.c)
target_link_libraries(stack_list_example stack_list)

# Queue (array based)
add_library(queue_array queue/queue_array.c)
target_include_directories(queue_array PUBLIC queue)
add_executable(queue_array_example queue/examples/queue_array_example.c)
target_link_libraries(queue_array_example queue_array)

# Queue (list based)
add_library(queue_list queue/queue_list.c)
target_include_directories(queue_list PUBLIC queue)
add_executable(queue_list_example queue/examples/queue_list_example.c)
target_link_libraries(queue_list_example queue_list)

# Binary Search Tree
add_library(bst bst/bst.c)
target_include_directories(bst PUBLIC bst)
add_executable(bst_example bst/examples/bst_example.c)
target_link_libraries(bst_example bst)
