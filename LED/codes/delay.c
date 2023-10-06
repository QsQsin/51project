#include <intrins.h>
//调用_nop_函数


/**
  * @brief  以毫秒为单位的延时函数，8051：12MHz,1个机器周期(nop)=12个振荡周期
  * @param  number_of_ms 延时多少毫秒
  * @retval 无
  */
void delay_ms(int number_of_ms){
	int i,j;
	for(i=0;i<number_of_ms;i++){
		for(j=0;j<1000;j++){
			_nop_();
		}
	}
}