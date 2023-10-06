#include <REGX52.H>
#include "LCD1602.h"
#include "delay.h"
#include "uart.h"
#include "timer.h"
#include "iic.h"
#include "AT24C02.h"
#include "adc0809.h"


void main(){
	unsigned int offset=0,i;
	unsigned int adc;
	LCD_Init();
	Timer0_init();
	UART_Init();
	for(i=1;i<27;i++){
		AT24C02_WriteByte(i,64+i);
		delay_ms(5);
	}
	//UART_SendByte(adc);
	while(1){
		adc=ADC0809_Read()*(5.0/255)*1000;
		if(offset>25)
			offset%=26;
		LCD_ShowNum(1,1,adc,4);//1,1,AT24C02_ReadByte(1+offset)
		LCD_ShowString(1,5,"mV");//
		delay_ms(100);
		offset++;
	}
}

//中断服务函数
void Timer_Routine()  interrupt 1 {
	//重置计时器初值
	TH0=( 65536 - 200 )/256;
	TL0=( 65536 - 200 )%256;
	P3_3=~P3_3;
	
}

void UART_Routine() interrupt 4 {
	if(RI==1){
		UART_SendByte(SBUF);
		RI=0;
	}
}
