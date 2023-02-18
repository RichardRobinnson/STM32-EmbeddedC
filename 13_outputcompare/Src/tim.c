#include "stm32f4xx.h"

#define TIM2_CLK_EN (1U<<0)
#define CR1_TIM2_EN (1U<<0)
#define CCER_EN_CH1 (1U<<0)
#define GPIOAEN (1U<<0)
#define PIN5 (1U<<5)

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


void tim2__pa5_output_compare(){
	//Set pa5 to alternative mode then we map the alternative function

	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER |=(1U<<11);
	GPIOA->MODER &= ~(1U<<10);

	GPIOA->AFR[0] |= (1U<<20);
	GPIOA->AFR[0] &= ~(1U<<21);
	GPIOA->AFR[0] &= ~(1U<<22);
	GPIOA->AFR[0] &= ~(1U<<23);


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
//set ouput compare toggle mode
TIM2->CCMR1 = (1U<<4) | (1U<<5);
//Enable capture compare tim2 ch1 in copmare mode
TIM2->CCER |= CCER_EN_CH1;




}
