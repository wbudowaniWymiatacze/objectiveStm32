/* 
 * File:   CUsart.cpp
 * Author: reymondo
 * 
 * Created on 8 listopad 2012, 17:09
 */

#include <CUsart.hpp>

CUsart::CUsart(CGpioManager * GM,SPeripheralConfig& config):
IPeripheral(GM)
{
    TPeripheralConfigUsart& A = (TPeripheralConfigUsart&)config;
    USARTx = A.usart;
    GPIO_Pin_Tx = GM->getGpio(A.gpioPort,
                                     A.gpioPinTx,
                                     GPIO_Speed_50MHz,
                                     GPIO_Mode_AF_PP);
    GPIO_Pin_Rx = GM->getGpio(A.gpioPort,
                                     A.gpioPinRx,
                                     GPIO_Speed_50MHz,
                                     GPIO_Mode_IN_FLOATING);
    
    ptr=0;
    buff[ptr]='\0';
}

CUsart::~CUsart()
{
    
}

void CUsart::init()
{
    GPIO_Pin_Tx->init();
    GPIO_Pin_Rx->init();
    
    USART_ClockInitTypeDef USART_ClockInitStructure;
    USART_InitTypeDef      USART_InitStructure;

    USART_ClockStructInit(&USART_ClockInitStructure);
    USART_ClockInit(USARTx, &USART_ClockInitStructure);

    USART_InitStructure.USART_BaudRate   = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits   = USART_StopBits_1;
    USART_InitStructure.USART_Parity     = USART_Parity_No;
    USART_InitStructure.USART_Mode       = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    //Write USART parameters
    USART_Init(USARTx, &USART_InitStructure);
    
    //Enable USART
    USART_Cmd(USARTx, ENABLE);
    //hmmm
    while( USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);

}

void CUsart::sendChar(char c)
{
	while( USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);
	USART_SendData(USARTx, (uint8_t) c);
}

char CUsart::readChar()
{
	return (char) USART_ReceiveData(USARTx);
}

void CUsart::sendString(const char * c)
{
	int i=0;
	while(c[i]!='\0')
	{
		sendChar(c[i++]);
	}
}

void CUsart::recCharHandler(char c)
{
	if (c=='\r')
	{
		sendChar((uint8_t)'\r');
		sendChar((uint8_t)'\n');
		sendString("Otrzymano komende: ");
		sendString(buff);
		sendChar((uint8_t)'\r');
		sendChar((uint8_t)'\n');
		sendChar((uint8_t)'>');
		ptr=0;
		buff[0]='\0';
		return;
	}
	if (ptr<64)
	{
		sendChar(c);
		buff[ptr]=c;
		buff[++ptr]='\0';
	}
}

	
