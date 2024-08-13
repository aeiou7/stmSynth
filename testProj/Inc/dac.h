#ifndef DAC_H_
#define DAC_H_
#include <stddef.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2s.h"
void dacInit(uint32_t sample_rate);
void dacInitGpio();
void dacInitI2S(uint32_t sample_rate);
void dacInitDMA();
void dacStop();
void dacFill();

#endif // DAC_H_
