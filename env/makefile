UNITY_ROOT=../../Unity
CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m4 -mthumb  -nostdlib
CPPFLAGS=-DSTM32F411Rx -D ARM_MATH_CM4\
				 -Ivendor/CMSIS/Device/ST/STM32F4/Include \
				 -Ivendor/CMSIS/Core/Include \
				 -I./inc \
				 -I $(UNITY_ROOT)/src

LINKER_FILE=linker_script.ld
LDFLAGS=-T $(LINKER_FILE)

BINARY = i2s.elf

PROGRAMMER = openocd
PROGRAMMER_FLAGS = -f interface/stlink.cfg -f target/stm32f4x.cfg
SRCS = src/main.c src/usart.c src/gpio.c src/i2s.c src/logging.c startup.c system_stm32f4xx.c
OBJS = $(SRCS:.c=.o)
all: $(BINARY)

$(BINARY): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $(BINARY)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
startup.o: startup.c
	$(CC) $(CFLAGS) $(CPPFLAGS) startup.c -c

system_stm32f4xx.o: system_stm32f4xx.c
	$(CC) $(CFLAGS) $(CPPFLAGS) system_stm32f4xx.c -c
test: $(UNITY_ROOT)/src/unity.c src/logging.c src/usart.c test/test.c test/test_runners/test_runner.c 
	gcc  $(CPPFLAGS) $^ -o test_stm32
test/test_runners/test_runner.c: test/test.c
	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb test/test.c test/test_runners/test_runner.c
.PHONY: clean
.PHONY: test
clean:
	rm -f *.o *.elf src/*.o src/*.elf

flash: $(BINARY)
	$(PROGRAMMER) $(PROGRAMMER_FLAGS) -c "program $(BINARY) verify reset exit"