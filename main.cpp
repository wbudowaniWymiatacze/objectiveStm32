/*
 * main.cpp
 *
 *  Created on: Jan 21, 2012
 *      Author: artur
 */

#include <stm32f10x.h>
#include <boardDefs.hpp>
#include <stm32f10x_spi.h>

#include <CGpioManager.hpp>

#include <CPeriphalManager.hpp>
#include <PeripheralTypes.hpp>
#include <IPeripheral.hpp>
#include <CLed.hpp>
#include <CUsart.hpp>
#include <CButton.hpp>

#include "ExternalModules/KamodRGB.hpp"
#include "ExternalModules/KamodMEMS2.hpp"
#include "Interrupts/IsrDispatcher.hpp"
#include "stm32f10x_exti.h"

#include <cstdio> 


void LIS35_ReadRegister(char addr,char * v);
void LIS35_WriteRegister(char addr,char v);
void LIS35_RebootMemory();
char InitializeLIS35();
void LIS35_GetPosition(signed char * x, signed char * y, signed char * z);


void ordinaryDelay(int val = 10000)
{
    for(int i=0;i<val;i++);
}

#define LIS35_ERROR 1
#define LIS35_OK 	0
#define LIS35_WRITE 0
#define LIS35_READ 	0x80
#define LIS35_ADDR_NO_INC 0
#define LIS35_ADDR_INC 0x40

#define LIS35_REG_OUTX 	0x29
#define LIS35_REG_OUTY	0x2B
#define LIS35_REG_OUTZ	0x2D

#define LIS35_REG_CR1 0x20
#define LIS35_REG_CR1_XEN 0x1
#define LIS35_REG_CR1_YEN 0x2
#define LIS35_REG_CR1_ZEN 0x4
#define LIS35_REG_CR1_DR_400HZ 0x80
#define LIS35_REG_CR1_ACTIVE 0x40
#define LIS35_REG_CR1_FULL_SCALE 0x20

#define LIS35_REG_CR2 0x21
#define LIS35_REG_CR2_BOOT 0x40

#define LIS35_CR3 0x22
#define LIS35_CR3_IHL 0x80
#define LIS35_CR3_CLICK_INT 0x7
#define LIS35_CR3_FF1_INT 0x1


#define LIS35_FF_WU_CFG_1 0x30
#define LIS35_FF_WU_SRC_1 0x31
#define LIS35_FF_WU_THS_1 0x32
#define LIS35_FF_WU_DURATION_1 0x33


#define LIS35_CLICK_CFG 0x38
#define LIS35_CLICK_THSY_X 0x3b
#define LIS35_CLICK_THSZ 0x3c
#define LIS35_CLICK_TIME_LIMIT 0x3D


#define LIS35_STATUS_REG 0x27


class LedToogler : public InterruptHandler
{
public:
    LedToogler( CLed* led): led(led){}
    
    void handleInterrupt()
    {
        led->toogle();
    }
private:
    CLed* led;
};

int main()
{

    SystemInit();
    ordinaryDelay();

    /*PERIPHERAL MANAGER TEST*/
    CGpioManager GM;    
    CPeriphalManager PM(&GM);

    TPeripheralConfigButton buttonConfig;
    buttonConfig.apb2 = RCC_APB2Periph_GPIOC;
    buttonConfig.gpioPin = GPIO_Pin_13;
    buttonConfig.gpioPort = GPIOC;
    
    CButton* tamper = PM.getPeripheral<CButton>(buttonConfig);
    tamper->init();
   
    TPeripheralConfigLed ledConfig;
    ledConfig.apb2 = RCC_APB2Periph_GPIOC;
    ledConfig.gpioPin = GPIO_Pin_6;
    ledConfig.gpioPort = GPIOC;
    
    CLed* greenLed = PM.getPeripheral<CLed>(ledConfig);
    greenLed->init();
    
    ledConfig.gpioPin = GPIO_Pin_7;
    
    CLed* yellowLed = PM.getPeripheral<CLed>(ledConfig);
    yellowLed->init();
   
    TPeripheralConfigUsart usartConfig;

    usartConfig.usart = USART2;
    usartConfig.apb1  = RCC_APB1Periph_USART2;
    usartConfig.apb2  = RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO ;
    usartConfig.remap = GPIO_Remap_USART2;
    usartConfig.gpioPinTx = GPIO_Pin_5;
    usartConfig.gpioPinRx = GPIO_Pin_6;
    usartConfig.gpioPort  = GPIOD;
    
    CUsart* Usart = PM.getPeripheral<CUsart>(usartConfig);
    Usart->init();

    IsrDispatcher isrDisp;
    LedToogler yellowLedToogler(yellowLed);
    LedToogler greenLedToogler(greenLed);
    
    
    TInterruptConfigExt tamperInterruptConfig;
    tamperInterruptConfig.preemptionPriority = 0;
    tamperInterruptConfig.subpriority        = 0;
    tamperInterruptConfig.channel            = EXTI15_10_IRQn;  
    tamperInterruptConfig.portSource = GPIO_PortSourceGPIOC;
    tamperInterruptConfig.pinSource  = GPIO_PinSource13;
    tamperInterruptConfig.line       = EXTI_Line13;
    tamperInterruptConfig.trigger    = EXTI_Trigger_Rising;
    
    isrDisp.registerInterrupt(EXTI15_10_IRQn,yellowLedToogler);
    isrDisp.enableInterruptExt(tamperInterruptConfig);    
    
    isrDisp.registerInterrupt(SysTick_IRQn,greenLedToogler);
    isrDisp.enableInterruptSysTick(1000000);
    
    Usart->sendString("\r\nSTART?\n\r");
    
        SPI_InitTypeDef  SPI_InitStructure;
  	GPIO_InitTypeDef GPIO_InitStructure;

  	// Enable SPI1 and GPIO clocks 
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3, ENABLE);
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOB , ENABLE);

  	// Configure SPI1 pins: SCK, MISO and MOSI 
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_Init(GPIOC, &GPIO_InitStructure);

  	// Configure I/O for Flash Chip select 
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  	GPIO_Init(GPIOB, &GPIO_InitStructure);
        

  	// SPI1 configuration 
  	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
  	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
  	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  	SPI_InitStructure.SPI_CRCPolynomial = 7;
  	SPI_Init(SPI3, &SPI_InitStructure);
  	
        GPIO_PinRemapConfig(GPIO_Remap_SPI3,ENABLE);
        
        // Enable SPI3        
  	SPI_Cmd(SPI3, ENABLE);
        
        ordinaryDelay();
        
        signed char x,y,z;
        char out[128];
        
	if (InitializeLIS35() == LIS35_ERROR)
	{
		while(1);
	}
    
    while(1)
    {
        ordinaryDelay(999999);
        LIS35_GetPosition(&x, &y, &z);
        Usart->sendString("\r               \r");
        sprintf(out,"[%d, %d, %d]",x, y, z);  	
        Usart->sendString(out);
    }   
    
}



/************************* SPI Functions **********************************************/

void SPI_Transmit(char cData)
{ 
    SPI_I2S_SendData(SPI3, cData);

    while (SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_RXNE) == RESET) { ; }

    SPI_I2S_ReceiveData(SPI3);
}


char SPI_Receive(void)
{
    SPI_I2S_SendData(SPI3, 0xFF);

    while (SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_RXNE) == RESET) { ; }

    return SPI_I2S_ReceiveData(SPI3);
}

void SPI_CS_Enable(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_15);
}

void SPI_CS_Disable(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_15);
}


/************************* SPI Functions - end *****************************************/

void LIS35_RebootMemory()
{
	SPI_CS_Enable();
	SPI_Transmit(LIS35_WRITE|LIS35_ADDR_NO_INC|LIS35_REG_CR2);
	SPI_Transmit(LIS35_REG_CR2_BOOT);
	SPI_CS_Disable();
}


char InitializeLIS35(void)
{
	char RegVal, LIS35Settings;
  
	//Reset LIS35 configuration
        LIS35_RebootMemory(); 

	LIS35_ReadRegister(LIS35_REG_CR1, &RegVal);

	//Power up
	LIS35Settings = LIS35_REG_CR1_XEN | LIS35_REG_CR1_YEN | LIS35_REG_CR1_ZEN | LIS35_REG_CR1_ACTIVE;
	LIS35_WriteRegister(LIS35_REG_CR1, LIS35Settings);
	LIS35_ReadRegister(LIS35_REG_CR1, &RegVal);

	//Check whether power up is set
	if (RegVal == LIS35Settings) 
            return LIS35_OK;

	return LIS35_ERROR;
}


void LIS35_ReadRegister(char addr,char * v)
{
	SPI_CS_Enable();
	SPI_Transmit(LIS35_READ|LIS35_ADDR_NO_INC|addr);
	*v=SPI_Receive();
	SPI_CS_Disable();
}


void LIS35_WriteRegister(char addr,char v)
{
	SPI_CS_Enable();
	SPI_Transmit(LIS35_WRITE|LIS35_ADDR_NO_INC|addr);
	SPI_Transmit(v);
	SPI_CS_Disable();
}

void LIS35_GetPosition(signed char * x, signed char * y, signed char * z)
{
	SPI_CS_Enable();
	SPI_Transmit(LIS35_READ|LIS35_ADDR_INC|LIS35_REG_OUTX);

	*x=SPI_Receive();
	SPI_Receive();
	*y=SPI_Receive();
	SPI_Receive();
	*z=SPI_Receive();
	SPI_CS_Disable();
}





