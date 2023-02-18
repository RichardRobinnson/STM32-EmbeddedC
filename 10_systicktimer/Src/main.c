#include "stm32f4xx.h"
#include "stdint.h"
#include <stdio.h>
#include "usart.h"
#include "adc.h"
#include "systick.h"

#define GPIOAEN (1U<<0)
#define PIN5 (1U<<5)

uint32_t key;

int main(void){
	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER |=(1U<<10);
	GPIOA->MODER &= ~(1U<<11);
	while(1){
	GPIOA->ODR ^= PIN5;
	Delayms(1000);
	}
}
