cmake_minimum_required(VERSION 3.12)
project(tipdat_microbit2 C)

set(CMAKE_C_STANDARD 11)

include_directories(2_uart)
include_directories(3_gpiote)
include_directories(4_accelerometer)
include_directories(5_pwm)

add_executable(tipdat_microbit2
        1_gpio/main.c
        2_uart/gpio.h
        3_gpiote/gpio.h
        3_gpiote/gpiote.h
        3_gpiote/ppi.h
        4_accelerometer/accel.c
        4_accelerometer/accel.h
        4_accelerometer/ubit_led_matrix.c
        4_accelerometer/ubit_led_matrix.h
        4_accelerometer/utility.c
        4_accelerometer/utility.h
        5_pwm/ppi.h
        5_pwm/pwm.c
        5_pwm/pwm.h
        5_pwm/timer.h
        5_pwm/utility.c
        5_pwm/utility.h)
