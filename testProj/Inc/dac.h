#ifndef DAC_H_
#define DAC_H_
#include <stddef.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"
void dacInit(uint32_t sample_rate, size_t blockSize);
void dacInitGpio();
void dacInitI2S(uint32_t sample_rate);
void dacInitDMA(size_t blockSize);
void dacStart();
void dacStop();
void dacFill(size_t offset);

#endif // DAC_H_
