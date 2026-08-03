cmake_minimum_required(VERSION 3.31)
project(DSA_C C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic -pedantic)

# Linked List
add_library(linked_list linked_list/linked_list.c)
target_include_directories(linked_list PUBLIC linked_list)
add_executable(linked_list_example linked_list/examples/linked_list_example.c)
target_link_libraries(linked_list_example linked_list)
