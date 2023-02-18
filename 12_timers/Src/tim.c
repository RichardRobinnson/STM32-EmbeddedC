#include "stm32f4xx.h"

#define TIM2_CLK_EN (1U<<0)
#define CR1_TIM2_EN (1U<<0)

void tim2_1hz_init(){
	//Give clock
RCC->APB1ENR |= TIM2_CLK_EN;
//Set prescalar
TIM2->PSC =1600 -1 ;//16 000 000 /1 600 =10 000
		//Set ARR
TIM2->ARR = 20000-1; //10000 /10000 =1s
//clock counter
TIM2->CNT =0;
//ENable Timer

TIM2-> CR1= CR1_TIM2_EN;




}

