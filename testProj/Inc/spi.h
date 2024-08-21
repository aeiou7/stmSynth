#ifndef SPI_H_
#define SPI_H_
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_spi.h"
#include "gpio.h"
#include <stdint.h>
void spiInit();
void spi1Write(uint8_t *data);
void spi2Write(uint8_t *data);
void spi3Write(uint8_t *data);

#endif // SPI_H_
