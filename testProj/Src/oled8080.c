// //this file implements the ssd1322 oled functions according to the 8080 interface.
// #include "oled8080.h"
// #include "gpio.h"
// #include "stm32f4xx_hal.h"
// #include "stm32f4xx_hal_gpio.h"

// uint16_t OLED_D_Pin[8] = { OLED_D0_Pin,OLED_D1_Pin,OLED_D2_Pin,OLED_D3_Pin,OLED_D4_Pin,OLED_D5_Pin,OLED_D6_Pin,OLED_D7_Pin};
// GPIO_TypeDef *OLED_D_Port[8] = { OLED_D0_GPIO_Port,OLED_D1_GPIO_Port,OLED_D2_GPIO_Port,OLED_D3_GPIO_Port,OLED_D4_GPIO_Port,OLED_D5_GPIO_Port,OLED_D6_GPIO_Port,OLED_D7_GPIO_Port};
// void oledInit(){
// // reset
//     HAL_GPIO_WritePin(OLED_RS_GPIO_Port, OLED_RS_Pin,GPIO_PIN_RESET);
//     HAL_Delay(100);
//     HAL_GPIO_WritePin(OLED_RS_GPIO_Port, OLED_RS_Pin,GPIO_PIN_SET);
//     HAL_Delay(100);
//     //cs low
//     HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_RESET);
//     oledCommand(0xFD);//unlock/lock command
//     oledData(0x12);//unlock
//     oledCommand(0xAE);//display off
//     oledCommand(0xB3);//set clock divider
//     oledData(0x91);//scale 9, div 1
//     oledCommand(0xCA);//set multiplex
//     oledData(0x3F);
//     oledCommand(0xA2);//set offset
//     oledData(0x00);
//     oledCommand(0xA1);//set start line
//     oledData(0x00);
//     oledCommand(0xA0);
//     oledData(0x14);//remap data bits and com scan direction remap
//     oledData(0x11);//enable dual com mode
//     oledCommand(0xB5);//disable io input
//     oledData(0x00);
//     oledCommand(0xAB);//function select
//     oledData(0x01);
//     oledCommand(0xB4);//vsl extern
//     oledData(0xA0);
//     oledData(0xFD);
//     oledCommand(0xC1);//set contrast
//     oledData(0xFF);
//     oledCommand(0xC7);//set master contrast
//     oledData(0x0F);
//     oledCommand(0xB9);//set greyscale
//     oledCommand(0xB1);//set phase length
//     oledData(0xE2);// phase 1 = 6 phase 2 = 14
//     oledCommand(0xD1);// driving scheme capability
//     oledData(0x82);
//     oledData(0x20);
//     oledCommand(0xBB);// first precharge
//     oledData(0x1F);
//     oledCommand(0xB6);// second precharge
//     oledData(0x08);
//     oledCommand(0xBE);//vcomh
//     oledData(0x07);
//     oledCommand(0xA6);//set default mode
//     oledCommand(0xA9);//no partial mode
//     HAL_Delay(10);// stabilize vdd
//     oledCommand(0xAF);// display on


//     oledCommand(0xFD);//unlock/lock command
//     oledData(0x16);//lock
//     //cs hi
//     HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_SET);


//     oledDrawRect(0, 30, 0, 30, 0xff);
// }
// //DC pin is set high for display data, low for commands
// void oledData(uint8_t data){
//     HAL_GPIO_WritePin(OLED_DC_GPIO_Port,OLED_DC_Pin, GPIO_PIN_SET);
//     oledWrite(data);
// }
// void oledCommand(uint8_t data){
//     HAL_GPIO_WritePin(OLED_DC_GPIO_Port,OLED_DC_Pin, GPIO_PIN_RESET);
//     oledWrite(data);
// }

// // this function handles the write logic for the 8080 interface
// // first it sets the wright line low to indicate an incoming bit.
// // then the pins are set in output mode, and each bit of data is sent over the corresponding wire
// // afterwards the write pin is pulled high again and the ports are returned to read state
// void oledWrite(uint8_t data){
//     HAL_GPIO_WritePin(OLED_WR_GPIO_Port, OLED_WR_Pin, GPIO_PIN_RESET);
//     for (int i = 0; i < 8; i++) {
//         gpioSetPinMode(OLED_D_Pin[i], OLED_D_Port[i], 1);
//     }
//     for (int i = 0; i < 8; i++) {
//         HAL_GPIO_WritePin(OLED_D_Port[i],OLED_D_Pin[i], (data & (1 << i)) >> i);
//             }
//     HAL_GPIO_WritePin(OLED_WR_GPIO_Port, OLED_WR_Pin, GPIO_PIN_SET);
//     for (int i = 0; i < 8; i++) {
//         gpioSetPinMode(OLED_D_Pin[i], OLED_D_Port[i], 0);
//     }
// }

// void oledSetColumnAddress(uint16_t start,uint16_t end){
//     HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_RESET);
//     oledCommand(0x15);    // Set column address
//     oledData(start);      // Start column
//     oledData(end);        // End column
//     HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_SET);
// }
// void oledSetRowAddress(uint8_t start, uint8_t end){
//     HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_RESET);
//     oledCommand(0x75);    // Set column address
//     oledData(start);      // Start column
//     oledData(end);        // End column
//     HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_SET);
// }
// void oledDrawRect(uint16_t startC,uint16_t endC, uint8_t startR, uint8_t endR, uint8_t clr){
//     oledSetColumnAddress(startC, endC);
//     oledSetRowAddress(startR, endR);

//     HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_RESET);
//     for (uint16_t i = 0; i < (endC - startC + 1) * (endR - startR + 1); i++) {
//         oledData(clr);  // Send the color value to fill the rectangle
//         oledData(clr);  // Each oledData() sends 4 pixels in 4-bit grayscale
//     }
//     HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_SET);

// }
// void oledRead(uint8_t data){

// }
