#include "stm32f4xx.h"
#include "stdint.h"
#include <stdio.h>
#include "usart.h"
#include "adc.h"

#define GPIOAEN (1U<<0)
#define PIN5 (1U<<5)

uint32_t key;

int main(void){
	uart2_rxtx_init();

	pa1_adc_init();
	start_conversion();

	while(1){
		key=adc_read();
		printf("Sensor value=%d\n\r",(int)key);
}
}
