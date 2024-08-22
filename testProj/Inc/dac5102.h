#ifndef DAC5102_H_
#define DAC5102_H_
#include <stddef.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2s.h"
void dac5102Init(uint32_t sample_rate);
void dac5102InitGpio();
void dac5102InitI2S(uint32_t sample_rate);
void dac5102InitDMA();
void dac5102Stop();
void dac5102Fill();

#endif // DAC5102_H_
