cmake_minimum_required(VERSION 3.16)
#set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/stm32_gcc.cmake)
set(PROJ_NAME "stm32-vco" CACHE INTERNAL "Project Name")
project($(PROJ_NAME) C ASM)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Device/ST/STM32F4xx/Include/)
#stm32_fetch_cmsis(F4)
#stm32_fetch_hal(F4)

set(CMSIS_INCLUDE_DIRS
  Drivers/CMSIS/Include
  Drivers/CMSIS/Device/ST/STM32F4xx/Include
)
set(CMSIS_SOURCES
  Drivers/CMSIS/Device/ST/STM32F4xx/Source/*
)
set(PROJECT_SOURCES
    src/main.c
)
add_executable(${PROJ_NAME} ${PROJECT_SOURCES})
add_subdirectory(Drivers)
find_package(CMSIS COMPONENTS STM32F411RE REQUIRED)
find_package(HAL COMPONENTS STM32F4 REQUIRED)
target_link_libraries(${PROJ_NAME} CMSIS::STM32::F411RE HAL::STM32:F4::RCC STM32::NoSys)
#stm32_print_size_of_target(stm32-fetch-f4)
