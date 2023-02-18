/*
 * usart.c
 *
 *  Created on: 18-Feb-2023
 *      Author: Richard Robinnson
 */
#include "usart.h"


#define GPIOAEN (1U<<0)
#define UART2EN (1U<<17)
#define SYS_CLK 16000000
#define UART_BAUDRATE 115200
#define CR1_TE (1U<<3)
#define CR1_UE (1U<<13)
#define SR_TXE (1U<<7)

#define GPIOAEN (1U<<0)
#define UART2EN (1U<<17)
#define SYS_CLK 16000000
#define UART_BAUDRATE 115200
#define CR1_TE (1U<<3)
#define CR1_UE (1U<<13)
#define SR_TXE (1U<<7)

static void uart_set_baudrate(USART_TypeDef *USARTx,uint32_t PeriphClk,uint32_t BaudRate);
static uint16_t compute_uart_div(uint32_t PeriphClk,uint32_t BaudRate);

void uart2_write(int ch);

int __io_putchar(int ch){
	uart2_write(ch);
	return ch;
}
void uart2_tx_init(void){
	/*
	 * ***********Configure Uart Gpio Pin******************
	 * Enable clock access to PA2(USART TX PIN from alternate function mapping table)
	 * Set PA2 mode as alternate function mode
	 * Set PA2 Alternate Function as Usart_TX (AF07)
	 * */
	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER |=(1U<<5);
	GPIOA->MODER &= ~(1U<<4);

	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);

	/**************************Configure uart mdoule************************************
	 * Enable Clock access uart2
	 * Configure BaudRate
	 * Configure the transfer Direction
	 * Enable uart mocule*/
	RCC->APB1ENR |= UART2EN;
	uart_set_baudrate(USART2,SYS_CLK,UART_BAUDRATE);
	USART2->CR1 = CR1_TE;
	USART2->CR1 |= CR1_UE;


}
static void uart_set_baudrate(USART_TypeDef *USARTx,uint32_t PeriphClk,uint32_t BaudRate){
	USARTx->BRR = compute_uart_div(PeriphClk,BaudRate);

}


static uint16_t compute_uart_div(uint32_t PeriphClk,uint32_t BaudRate){
	return ((PeriphClk+(BaudRate/2U))/BaudRate);
}

void uart2_write(int ch){
	/*
	 * Make sure the tx data register is empty
	 * Write to transmit data register
	 * */
	while(!(USART2->SR & SR_TXE)){}
	USART2->DR =(ch & 0xFF);
}
