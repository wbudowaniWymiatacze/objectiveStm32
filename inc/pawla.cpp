/*
 * pawla.cpp
 *
 *  Created on: Feb 4, 2012
 *      Author: artur
 */

enum EUsart {
	EUsart1,
	EUsart2
};

class CGpio
{
  public:
	CGpio();
	int Init();
	int DeInit();
	~CGpio();

  private:
	GPIO_InitTypeDef m_Pin;
	GPIO_TypeDef     m_Port;
};

struct CUsartGpios
{
	CGpio m_gpioRx;
	CGpio m_gpioTx;
};

class Usart
{
  public:
	Usart(EUsart);
	int Init();
	int DeInit();

  private:
	CUsartGpios  m_gpios;
};
