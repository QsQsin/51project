#include <REGX52.H>
#include "delay.h"


/**
  * @brief  串口通信配置函数
  * @param  无
  * @retval 无
  */
void UART_Init(){
	//配置控制UART的PCON和SCON
	//方式1
	SCON=0x50;
	PCON |= 0x80;
	//配置定时器进而得到波特率
	TMOD &= 0x0F;       //设置定时器1为8位自动重载，溢出时TH1存放的值自动装入TL1
	TMOD |= 0x20;
  TL1 = 0xF3;         //设定定时器初值，4800Baud Rate
	TH1 = 0xF3;         //设定定时重装值
	//配置中断
	EA=1;               //允许总中断
	ES=1;               //允许UART中断
	ET1 = 0;            //禁止定时器1中断
	TR1 = 1;            //允许计数
	
}


/**
  * @brief  串口通信发送字符函数
  * @param  Byte 将要发送的8位字符，2字节
  * @retval 无
  */
void UART_SendByte(unsigned char Byte){
	SBUF=Byte;   //SBUF就是要发送或接受的数据缓存单元，8bit
	while(TI==0);//等待是否发送完成
	TI=0;        //软件置位
}

