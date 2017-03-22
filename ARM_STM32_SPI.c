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


void ARM_STM32_SPI_Init_Pins(uint8_t spi_num, uint8_t spi_gpio_speed, GPIO_TypeDef* spi_cs_port, uint16_t spi_cs_pin_num)
{
	//INTIALIZE SPI GPIO PINS DEPENDING ON WHICH SPI PERIPHERAL IS SPECIFIED
	
	#ifdef STM32F103
	GPIO_InitTypeDef gpio;
	if(spi_num == ARM_STM32_SPI_PERIPHERAL_SPI1)
	{
		//SPI1 PERIPHERAL
		gpio.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
		gpio.GPIO_Mode = GPIO_Mode_AF_PP;
		gpio.GPIO_Speed = (GPIOSpeed_TypeDef)spi_gpio_speed;
		GPIO_Init(GPIOA, &gpio);
	}
	else if(spi_num == ARM_STM32_SPI_PERIPHERAL_SPI2)
	{
		//SPI2 PERIPHERAL
		gpio.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
		gpio.GPIO_Mode = GPIO_Mode_AF_PP;
		gpio.GPIO_Speed = (GPIOSpeed_TypeDef)spi_gpio_speed;
		GPIO_Init(GPIOB, &gpio);
	}
	
	//SET CS PIN TO PUT PUSH PULL
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = (GPIOSpeed_TypeDef)spi_gpio_speed;
	gpio.GPIO_Pin = spi_cs_pin_num;
	GPIO_Init(spi_cs_port, &gpio);
	
	//SET CS TO HIGH
	GPIO_SetBits(spi_cs_port, spi_cs_pin_num);
	#endif
}

void ARM_STM32_SPI_Set_Parameters(uint8_t spi_num, uint16_t spi_datasize, uint16_t spi_speed, uint16_t spi_direction, uint16_t spi_msb_lsb_first)
{
	//SET THE PARAMETERS OF THE SPECIFIED SPI
	
	#ifdef STM32F103
	if(spi_num == ARM_STM32_SPI_PERIPHERAL_SPI1)
	{
		//SPI1 PERIPHERAL
		
		//ENABLE CLOCK TO SPI1
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
		
		//CONFIGURE SPI1 PARAMETERS
		SPI_InitTypeDef spi;
		
		spi.SPI_DataSize = spi_datasize;
		spi.SPI_BaudRatePrescaler= spi_speed;
		spi.SPI_Direction = spi_direction;
		spi.SPI_FirstBit = spi_msb_lsb_first;
		spi.SPI_CPHA = SPI_CPHA_1Edge;
		spi.SPI_CPOL = SPI_CPOL_Low;
		spi.SPI_Mode = SPI_Mode_Master;
		spi.SPI_NSS = SPI_NSS_Soft;
		
		SPI_Init(SPI1, &spi);
	}
	else if(spi_num == ARM_STM32_SPI_PERIPHERAL_SPI2)
	{
		//SPI2 PERIPHERAL
		
		//ENABLE CLOCK TO SPI1
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
		
		SPI_InitTypeDef spi;
		
		spi.SPI_DataSize = spi_datasize;
		spi.SPI_BaudRatePrescaler= spi_speed;
		spi.SPI_Direction = spi_direction;
		spi.SPI_FirstBit = spi_msb_lsb_first;
		spi.SPI_CPHA = SPI_CPHA_1Edge;
		spi.SPI_CPOL = SPI_CPOL_Low;
		spi.SPI_Mode = SPI_Mode_Master;
		spi.SPI_NSS = SPI_NSS_Soft;
		
		SPI_Init(SPI2, &spi);
	}
	#endif
}

void ARM_STM32_SPI_Start(uint8_t spi_num)
{
	//START SPECIDIED SPI PERIPHERAL
	
	#ifdef STM32F103
	if(spi_num == ARM_STM32_SPI_PERIPHERAL_SPI1)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
		SPI_Cmd(SPI1, ENABLE);
	}
	else if (spi_num == ARM_STM32_SPI_PERIPHERAL_SPI2)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
		SPI_Cmd(SPI1, ENABLE);
	}
	#endif
}

void ARM_STM32_SPI_Stop(uint8_t spi_num)
{
	//DISABLE THE SPECIFIED SPI AND STOP CLOCK TO IT
	
	#ifdef STM32F103
	if(spi_num == ARM_STM32_SPI_PERIPHERAL_SPI1)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, DISABLE);
		SPI_Cmd(SPI1, DISABLE);
	}
	else if (spi_num == ARM_STM32_SPI_PERIPHERAL_SPI2)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, DISABLE);
		SPI_Cmd(SPI2, DISABLE);
	}
	#endif
}
void ARM_STM32_SPI_Send_Data(void);

void ARM_STM32_SPI_Deinit(uint8_t spi_num)
{
	//DEINTIALIZE THE SPI PERPHERAL
	
	#ifdef STM32F103
	if(spi_num == ARM_STM32_SPI_PERIPHERAL_SPI1)
	{
		//SPI1 PERIPHERAL
		SPI_I2S_DeInit(SPI1);
	}
	else if (spi_num == ARM_STM32_SPI_PERIPHERAL_SPI2)
	{
		//SPI2 PERIPHERAL
		SPI_I2S_DeInit(SPI2);
	}
	#endif
}
