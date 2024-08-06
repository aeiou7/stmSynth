cmake_minimum_required(VERSION 3.16)
set(CMAKE_TOOLCHAIN_FILE toolchain.cmake)
project(firmware C ASM)

### toolchain.cmake ###
# this is required
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# specify the cross compiler
SET(CMAKE_C_COMPILER   /Applications/ArmGNUToolchain/12.2.mpacbti-rel1/arm-none-eabi/bin/arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
SET(CMAKE_CXX_COMPILER /Applications/ArmGNUToolchain/12.2.mpacbti-rel1/arm-none-eabi/bin/arm-none-eabi-g++)
message(STATUS "C_FLAGSarm64: ${C_FLAGSarm64}")
# where is the target environment
SET(CMAKE_FIND_ROOT_PATH  /Applications/ArmGNUToolchain/12.2.mpacbti-rel1/arm-none-eabi)

# search for programs in the build host directories (not necessary)
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)


# Set the C/C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)


include_directories(inc/)
include_directories(vendor/CMSIS/Core/Include)
include_directories(vendor/CMSIS/Device/ST/STM32F4/Include)
include_directories(vendor/CMSIS/DSP/Include)
set(C_SOURCES 
system_stm32f4xx.c
src/main.c
src/gpio.c
src/usart.c
src/logging.c
src/i2s.c
)
set(EXECUTABLE ${PROJECT_NAME}.elf)
add_executable(${EXECUTABLE} ${C_SOURCES} startup.c)
target_compile_definitions(${EXECUTABLE} PRIVATE
        -DSTM32F411xE
)
target_compile_options(${EXECUTABLE} PRIVATE
        -mcpu=cortex-m4
        -mthumb

        -nostdlib

        -Wall

)
# Add the linker script
target_link_options(${EXECUTABLE} PRIVATE
    -T ../linker_script.ld
    -nostdlib
    -lgcc
    /Applications/ArmGNUToolchain/12.2.mpacbti-rel1/arm-none-eabi/lib/gcc/arm-none-eabi/12.2.1/libgcc.a 
    ../vendor/CMSIS/Lib/ARM/arm_cortexM4bf_math.lib
)