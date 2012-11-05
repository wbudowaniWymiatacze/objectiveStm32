/* 
 * File:   CI2C.cpp
 * Author: reymondo
 * 
 * Created on 18 czerwiec 2012, 20:28
 */

#include <CI2C.hpp>

CI2C::CI2C(CGpioManager * GM,SPeripheralConfig& config ): 
IPeripheral(GM)
{
    TPeripheralConfigI2C& A = (TPeripheralConfigI2C&)config;
    I2Cx = A.i2c;
    GPIO_Pin_SCL = GM->getGpio<CGpioI2C>(A.gpioPort,A.gpioPinScl, GPIO_Speed_50MHz);
    GPIO_Pin_SDA = GM->getGpio<CGpioI2C>(A.gpioPort,A.gpioPinSda, GPIO_Speed_50MHz);
    
}

CI2C::~CI2C() {
}

void CI2C::init()
{
    GPIO_Pin_SCL->init();
    GPIO_Pin_SDA->init();
    
    I2C_InitTypeDef I2C_InitStructure;

    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStructure.I2C_OwnAddress1 = 0x03; //TODO: to check if can be different
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_InitStructure.I2C_ClockSpeed = 200000;
    I2C_Init(I2Cx, &I2C_InitStructure);

    I2C_Cmd(I2Cx, ENABLE);

}

void CI2C::sendBytesAndStop(unsigned char addr, unsigned char * buff, unsigned char len)
{
    sendBytes(addr,buff,len);
    I2C_GenerateSTOP(I2Cx, ENABLE);

}
void CI2C::sendBytes(unsigned char addr, unsigned char * buff, unsigned char len)
{
    I2C_GenerateSTART(I2Cx, ENABLE);
    while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT));
    I2C_Send7bitAddress(I2Cx, addr, I2C_Direction_Transmitter);
    while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
    for(unsigned char i=0 ; i<len ; i++)
    {
            I2C_SendData(I2Cx,buff[i]);
            while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
    }

}

void CI2C::readBytes(unsigned char addr, unsigned char * b, unsigned char len)
{
    I2C_AcknowledgeConfig(I2Cx,ENABLE);

    I2C_GenerateSTART(I2Cx, ENABLE);
    while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT));

    I2C_Send7bitAddress(I2Cx, addr, I2C_Direction_Receiver);
    while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));

    for(int i=0 ; i<len ; i++)
    {
            if(i==len-1)
            {
                     I2C_AcknowledgeConfig(I2Cx,DISABLE);
            }
            while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED));
            b[i]=I2C_ReceiveData(I2Cx);
    }
    I2C_GenerateSTOP(I2Cx, ENABLE);

}