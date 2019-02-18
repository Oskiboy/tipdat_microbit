cmake_minimum_required(VERSION 3.12)
project(2_uart C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(2_uart
        gpio.h
        main.c
        uart.c
        uart.h)
