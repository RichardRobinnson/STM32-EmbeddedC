#include "stm32f4xx.h"

#define SYSTICK_LOAD_VAL 32000
#define CNTRL_ENB (1U<<0)
#define CNTRL_CLCK (1U<<2)
#define COUNT_FLAG (1U<<16)

void Delayms(int n){
SysTick->LOAD = SYSTICK_LOAD_VAL;
SysTick->VAL =0;
SysTick->CTRL =(CNTRL_ENB | CNTRL_CLCK);
for(int i=0;i<n;i++){
	//wait for count flag to set
	while((SysTick->CTRL & COUNT_FLAG)==0){}
}
SysTick->CTRL =0;
}
