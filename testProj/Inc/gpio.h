#ifndef GPIO_H_
#define GPIO_H_
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include <stdint.h>

#define SPI1_RS_Pin GPIO_PIN_0
#define SPI1_RS_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define SPI1_CS_Pin GPIO_PIN_6
#define SPI1_CS_GPIO_Port GPIOA
#define SPI1_DC_Pin GPIO_PIN_2
#define SPI1_DC_GPIO_Port GPIOB
#define SPI2_CLR_Pin GPIO_PIN_8
#define SPI2_CLR_GPIO_Port GPIOA
#define SPI2_SYNC_Pin GPIO_PIN_9
#define SPI2_SYNC_GPIO_Port GPIOA
#define SPI2_LDAC_Pin GPIO_PIN_10
#define SPI2_LDAC_GPIO_Port GPIOA
#define SPI3_SYNC_Pin GPIO_PIN_11
#define SPI3_SYNC_GPIO_Port GPIOA
#define SPI3_LDAC_Pin GPIO_PIN_12
#define SPI3_LDAC_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SPI3_CLR_Pin GPIO_PIN_15
#define SPI3_CLR_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

void gpioInit();
void gpioSpi1Init();
void gpioSpi1DCSet(uint8_t state);
void gpioSpi1RSSet(uint8_t state);
void gpioSpi1CSSet(uint8_t state);
void gpioSpi2Init();
void gpioSpi3Init();
void gpioSetPinMode(uint16_t pin, GPIO_TypeDef *port, uint8_t mode);
#endif // GPIO_H_
