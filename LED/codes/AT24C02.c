#include <REGX52.H>
#include "iic.h"
#define AT24C02_ADDRESS 0xA0    //该元件地址：1010+A2A1A0+w A2A1A0为可配地址，一般为000


/**
  * @brief  AT24C02_EEPROM 写字节
  * @param  无
  * @retval 无
  */
void AT24C02_WriteByte(unsigned char WordAddress , Data){
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS); 
	I2C_ReceiveAck();
	I2C_SendByte(WordAddress);
	I2C_ReceiveAck();
	I2C_SendByte(Data);
	I2C_ReceiveAck();
	I2C_Stop();
}

/**
  * @brief  
  * @param  无
  * @retval 无
  */
unsigned char AT24C02_ReadByte(unsigned char WordAddress){
	unsigned char Data;
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS); 
	I2C_ReceiveAck();
	I2C_SendByte(WordAddress);
	I2C_ReceiveAck();
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS | 0x01);
	I2C_ReceiveAck();
	Data=I2C_ReceiveByte();
	I2C_SendAck(1);
	I2C_Stop();
	return Data;
}