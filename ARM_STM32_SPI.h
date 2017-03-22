/*************************************************************************
* STM32 SPI LIBRARY (SPL WRAPPER)
*
* SUPPORTS ONLY SPI MASTER MODE
* SUPPORTS CS SOFTWARE MODE ONLY (NO HARDWARE SUPPORT)
*	SUPPORTS ONLY DEFAULT SPI PIN (NO PIN REMAPPING)
*
* MARCH 22 2016
* ANKIT BHATNAGAR
* ANKIT.BHATNAGARINDIA@GMAIL.COM
*
* REFERENCES
* ***********************************************************************/

#ifndef _ARM_STM32_SPI_
#define _ARM_STM32_SPI_

#include <stdint.h>
//CHECK WHAT MCU US BEING USED IN ORDER TO INCLUDE
//THE RIGHT FILE FROM STM SPL
//THE MCU SHOULD BE DEFINED IN TARGET OPTIONS -> C/C++
#ifdef STM32F103
	#include "stm32f10x_spi.h"
	#include "stm32f10x_gpio.h"
	
	#define SPI_PERIPHERAL_SPI1	1
	#define SPI_PERIPHERAL_SPI2	2
	
	#define SPI_GPIO_SPEED_2MHZ 	2
	#define SPI_GPIO_SPEED_10MHZ 	1
	#define SPI_GPIO_SPEED_50MHZ	3
	
	#define SPI_CS_HARD
#endif

#ifdef STM32F072
#endif


void SPI_Init_Pins(uint8_t spi_num, uint8_t spi_gpio_speed, GPIO_TypeDef* spi_cs_port, uint16_t spi_cs_pin_num);
void SPI_Set_Parameters(uint8_t spi_num);
void SPI_Send_Data(void);

#endif
