/*************************************************************************
* STM32 SPI LIBRARY (SPL WRAPPER)
*
* SUPPORTS ONLY SPI MASTER MODE
* SUPPORTS CS SOFTWARE MODE ONLY (NO HARDWARE SUPPORT)
*	SUPPORTS ONLY DEFAULT SPI PINS (NO PIN REMAPPING)
*
* LIBRARY HAS NO CONTROL OVER THE /CS PIN. THAT IS REPSONSIBILITY OF
* USER APPLICATION
*
*
* MARCH 22 2017
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
	#include "stm32f10x.h"
	#include "stm32f10x_spi.h"
	#include "stm32f10x_gpio.h"
	
	#define ARM_STM32_SPI_PERIPHERAL_SPI1	1
	#define ARM_STM32_SPI_PERIPHERAL_SPI2	2
	
	#define ARM_STM32_SPI_GPIO_SPEED_2MHZ 	2
	#define ARM_STM32_SPI_GPIO_SPEED_10MHZ 	1
	#define ARM_STM32_SPI_GPIO_SPEED_50MHZ	3
	
	#define ARM_STM32_SPI_DATASIZE_16	SPI_DataSize_16b
	#define ARM_STM32_SPI_DATASIZE_8 	SPI_DataSize_8b
	
	#define ARM_STM32_SPI_BAUD_PRESCALER_2		SPI_BaudRatePrescaler_2
	#define ARM_STM32_SPI_BAUD_PRESCALER_4 		SPI_BaudRatePrescaler_4
	#define ARM_STM32_SPI_BAUD_PRESCALER_8 		SPI_BaudRatePrescaler_8
	#define ARM_STM32_SPI_BAUD_PRESCALER_16 	SPI_BaudRatePrescaler_16
	#define ARM_STM32_SPI_BAUD_PRESCALER_32 	SPI_BaudRatePrescaler_32
	#define ARM_STM32_SPI_BAUD_PRESCALER_64 	SPI_BaudRatePrescaler_64
	#define ARM_STM32_SPI_BAUD_PRESCALER_128	SPI_BaudRatePrescaler_128
	#define ARM_STM32_SPI_BAUD_PRESCALER_256	SPI_BaudRatePrescaler_256

	#define ARM_STM32_SPI_MSB_FIRST	SPI_FirstBit_MSB
	#define ARM_STM32_SPI_LSB_FIRST	SPI_FirstBit_LSB
	
	#define ARM_STM32_SPI_DIRECTION_2LINE_FULLDUPLEX	SPI_Direction_2Lines_FullDuplex
	#define ARM_STM32_SPI_DIRECTION_2LINE_RX_ONLY			SPI_Direction_2Lines_RxOnly
	#define ARM_STM32_SPI_DIRECTION_1LINE_RX					SPI_Direction_1Line_Rx 
	#define ARM_STM32_SPI_DIRECTION_1LINE_TX					SPI_Direction_1Line_Tx
#endif

#ifdef STM32F072

#endif


void ARM_STM32_SPI_Init_Pins(uint8_t spi_num, uint8_t spi_gpio_speed, GPIO_TypeDef* spi_cs_port, uint16_t spi_cs_pin_num);
void ARM_STM32_SPI_Set_Parameters(uint8_t spi_num, uint16_t spi_datasize, uint16_t spi_speed, uint16_t spi_direction, uint16_t spi_msb_lsb_first);

void ARM_STM32_SPI_Start(uint8_t spi_num);
void ARM_STM32_SPI_Stop(uint8_t spi_num);

uint16_t ARM_STM32_SPI_Send_Get_Data(uint8_t spi_num, uint16_t data);
uint16_t ARM_STM32_SPI_Send_Get_Data_Spi1(uint16_t data);
uint16_t ARM_STM32_SPI_Send_Get_Data_Spi2(uint16_t data);

void ARM_STM32_SPI_Deinit(uint8_t spi_num);

#endif
