/*
 * usart.h
 *
 *  Created on: 18-Feb-2023
 *      Author: Richard Robinnson
 */

#ifndef USART_H_
#define USART_H_

#include "stm32f4xx.h"
#include "stdint.h"
char uart2_read();
void uart2_rxtx_init(void);
void uart2_tx_init(void);

#endif /* USART_H_ */
