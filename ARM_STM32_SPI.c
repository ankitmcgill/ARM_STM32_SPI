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


#include "ARM_STM32_SPI.h"


void SPI_Init_Pins(uint8_t spi_num, uint8_t spi_gpio_speed, GPIO_TypeDef* spi_cs_port, uint16_t spi_cs_pin_num)
{
	//INTIALIZE SPI GPIO PINS DEPENDING ON WHICH SPI PERIPHERAL IS SPECIFIED
	
	GPIO_InitTypeDef gpio;
	if(spi_num == SPI_PERIPHERAL_SPI1)
	{
		gpio.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
		gpio.GPIO_Mode = GPIO_Mode_AF_PP;
		gpio.GPIO_Speed = (GPIOSpeed_TypeDef)spi_gpio_speed;
		GPIO_Init(GPIOA, &gpio);
	}
	else if(spi_num == SPI_PERIPHERAL_SPI2)
	{
		gpio.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
		gpio.GPIO_Mode = GPIO_Mode_AF_PP;
		gpio.GPIO_Speed = (GPIOSpeed_TypeDef)spi_gpio_speed;
		GPIO_Init(GPIOB, &gpio);
	}
	
	//SET CS PIN
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = (GPIOSpeed_TypeDef)spi_gpio_speed;
	gpio.GPIO_Pin = spi_cs_pin_num;
	GPIO_Init(spi_cs_port, &gpio);
	
	//SET CS TO HIGH
	GPIO_SetBits(spi_cs_port, spi_cs_pin_num);
}

void SPI_Set_Parameters(uint8_t spi_num)
{
	//SET THE PARAMETERS OF THE SPECIFIED SPI
	
	if(spi_num == SPI_PERIPHERAL_SPI1)
	{
		
	}
	else if(spi_num == SPI_PERIPHERAL_SPI2)
	{
		
	}
}

void SPI_Send_Data(void);
