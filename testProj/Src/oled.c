#include "oled.h"
#include "gpio.h"
#include "spi.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#define DATA 0
#define COMMAND 1

void oledInit() {
  spiInit();
  gpioSpi1RSSet(GPIO_PIN_RESET);
  HAL_Delay(5);
  gpioSpi1RSSet(GPIO_PIN_SET);
  HAL_Delay(50);
 	HAL_Delay(50);                 //50ms delay
	oledCommand(0xFD);     //set Command unlock
	oledData(0x12);
	oledCommand(0xAE);     //set display off
	oledCommand(0xB3);     //set display clock divide ratio
	oledData(0x91);
	oledCommand(0xCA);     //set multiplex ratio
	oledData(0x3F);
	oledCommand(0xA2);   //set display offset to 0
	oledData(0x00);
	oledCommand(0xA1);   //start display start line to 0
	oledData(0x00);
	oledCommand(0xA0);   //set remap and dual COM Line Mode
	oledData(0x14);
	oledData(0x11);
	oledCommand(0xB5);   //disable IO input
	oledData(0x00);
	oledCommand(0xAB);   //function select
	oledData(0x01);
	oledCommand(0xB4);   //enable VSL extern
	oledData(0xA0);
	oledData(0xFD);
	oledCommand(0xC1);   //set contrast current
	oledData(0xFF);
	oledCommand(0xC7);   //set master contrast current
	oledData(0x0F);
	oledCommand(0xB9);   //default grayscale
	oledCommand(0xB1);   //set phase length
	oledData(0xE2);
	oledCommand(0xD1);   //enhance driving scheme capability
	oledData(0x82);
	oledData(0x20);
	oledCommand(0xBB);   //first pre charge voltage
	oledData(0x1F);
	oledCommand(0xB6);   //second pre charge voltage
	oledData(0x08);
	oledCommand(0xBE);   //VCOMH
	oledData(0x07);
	oledCommand(0xA6);   //set normal display mode
	oledCommand(0xA9);   //no partial mode
	HAL_Delay(10);               //stabilize VDD
	oledCommand(0xAF);   //display on
	oledCommand(0xA5);   //display on
	HAL_Delay(50);               //stabilize VDD
  // write oled init
}

void oledCommand(uint8_t data) {
    gpioSpi1CSSet(GPIO_PIN_RESET);
    gpioSpi1DCSet(GPIO_PIN_RESET);
    spi1Write(&data);
    gpioSpi1CSSet(GPIO_PIN_SET);
}
void oledData(uint8_t data) {
    gpioSpi1CSSet(GPIO_PIN_RESET);
    gpioSpi1DCSet(GPIO_PIN_RESET);
    spi1Write(&data);
    gpioSpi1CSSet(GPIO_PIN_SET);
}
void oledDrawPixel{

}
