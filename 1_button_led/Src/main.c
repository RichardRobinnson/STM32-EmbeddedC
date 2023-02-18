#include "stm32f4xx.h"




#define GPIOAEN (1U<<0)
#define GPIOCEN (1U<<2)
#define PIN5 (1U<<5)
#define BTN (1U<<13)

/*
 * OR:
 * 0000 0000 0000 0000
 * 0000 0010 0000 0000
 * -------------------
 * 0000 0010 0000 0000
 *
 *
 * AND:
 * 0000 0000 0000 0000
 * 1111 1011 1111 1111
 * -------------------
 * 0000 0000 0000 0000
 *
 * XOR:
 * 0000 0000 0000 0000
 * 0000 0010 0000 0000
 * -------------------
 * 0000 0010 0000 0000
 * 0000 0010 0000 0000
 * -------------------
 * 0000 0000 0000 0000
 * */



int main(void){
	RCC->AHB1ENR |= GPIOAEN;
	RCC->AHB1ENR |= GPIOCEN;
	//Mode for GPIOA
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);
	//Mode for GPIOC
	GPIOC->MODER &= ~(1U<<26);
	GPIOC->MODER &= ~(1U<<27);
	while(1){
		/*
		 *	   0000 0000 0001 0000
		 * AND 0000 0000 0001 0000
		 * -------------------------
		 *     0000 0000 0001 0000
		 * */
		if(!(GPIOC->IDR & BTN)){	//0000 0000

			GPIOA->BSRR |= PIN5;
		}else{
			GPIOA->BSRR |= (1U<<21);
		}

	}
}

