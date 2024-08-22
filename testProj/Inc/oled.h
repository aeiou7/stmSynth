#ifndef OLED_H_
#define OLED_H_
#include <stdint.h>
#include "spi.h"
#define WIDTH 256
#define HEIGHT 64
void oledInit();
void oledData(uint8_t data);
void oledCommand(uint8_t data);
void oledWrite(uint8_t data);
void oledRead(uint8_t data);
void oledSetColumnAddress(uint16_t startC,uint16_t endC);
void oledSetRowAddress(uint8_t startR, uint8_t endR);
void oledDrawRect(uint16_t startC,uint16_t endC, uint8_t startR, uint8_t endR, uint8_t clr);
#endif // OLED_H_
