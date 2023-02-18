#include "stm32f4xx.h"
#include "stdint.h"
#include <stdio.h>
#include "usart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"

#define GPIOAEN (1U<<0)
#define PIN5 (1U<<5)

/*Set up connect a jumper wire from pa5 to pa6
 **/
int timestamp =0;
int main(){
	tim2__pa5_output_compare();
	tim3_pa6_input_compare();
	while(1){
		//Wait until edge is captured
		while(1){
			while(!(TIM3->SR & SR_CC1IF)){}
			timestamp =TIM3->CCR1;
		}
	}
	return 0;

}



