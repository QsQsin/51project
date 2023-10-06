#include <REGX52.H>
/*
sbit ADDA=P2^2;
sbit ADDB=P2^3;
sbit ADDC=P2^4;                 //可选地址 CBA
*/


//sbit ALE=P3^4;                  //地址锁存信号
sbit START=P3^5;                //AD转换启动信号
sbit EOC=P3^6;                  //AD转换结束信号
sbit OE=P3^2;               //数据输出允许信号
sbit CLOCK=P3^3;                //时钟信号

unsigned int ADC0809_Read(){
	unsigned int ADC_Result=0;
	START = 0;
	START = 1;
	START = 0;
	while(EOC==0);
	OE=1;
	ADC_Result=P1;
	OE=0;
	return ADC_Result;
}