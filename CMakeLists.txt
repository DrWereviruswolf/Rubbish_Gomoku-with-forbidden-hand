cmake_minimum_required(VERSION 3.10)
project(chess C)

set(CMAKE_C_STANDARD 11)

add_executable(chess main.c)

add_executable(temp temp.c)

add_executable(gomoku body/mainFuction.c body/part12.c body/value.c body/AI.c body/forbiddenHand.c)

add_compile_options(-Wall -Wextra)

add_executable(generator openMindTree/generator.c openMindTree/part12.c openMindTree/value.c openMindTree/whowin.c openMindTree/algor.c)