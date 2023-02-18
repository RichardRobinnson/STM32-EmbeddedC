#include "adc.h"
#include "stm32f4xx.h"
#include "stdint.h"

//
#define ADCENR (1U<<8)
#define ADDON (1U<<0)
#define CR2_SWSTART (1U<<30)
#define SR_EOC (1U<<1)


void pa1_adc_init(){
//See additional functions from data sheet table to find which pin can perform which adc fn.
//Since PA1 is the acd_1 pin we choose pa1 for our project
RCC->AHB1ENR |= (1U<<0);

GPIOA->MODER |= (1U<<2);
GPIOA->MODER |= (1U<<3);
/*
 * Enable clock
 *Select Sequence( if the conversion starts from seq 13 then 13th bit is set)
 *Select length(if use only one sensor then seq is 1)
 * */
RCC->APB2ENR |= ADCENR;
ADC1->SQR3 = (1U<<0);//channel 1 is set is we want to set channel 2 we us (1U<<1)
ADC1->SQR1 &= ~(1U<<20);
ADC1->SQR1 &= ~(1U<<21);
ADC1->SQR1 &= ~(1U<<22);
ADC1->SQR1 &= ~(1U<<23);//or set seq_len as 0x00 then use adc1->sqr1 =seq_len

ADC1->CR2 |= ADDON;

}

void start_conversion(){
	ADC1->CR2 |= CR2_SWSTART;
}
int adc_read(){
//wait for conversion to finish by checking eoc which stand for end of conversion
while(!(ADC1->SR & SR_EOC)){}
//Read the data then
return (ADC1->DR);
}
