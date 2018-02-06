cmake_minimum_required(VERSION 3.8)
project(Producer_Consumer)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(Producer_Consumer ${SOURCE_FILES})