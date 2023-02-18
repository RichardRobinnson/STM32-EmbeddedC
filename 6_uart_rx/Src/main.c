#include "stm32f4xx.h"
#include "stdint.h"
#include <stdio.h>
#include "usart.h"

#define GPIOAEN (1U<<0)
#define PIN5 (1U<<5)

char key;

int main(void){
	uart2_rxtx_init();

	while(1){
		key=uart2_read();
		printf("%c\n\r",key);
}
}
