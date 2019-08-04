/**
  ******************************************************************************
  * @file    delay.c 
  * @author  Pranjal Shrivastava
  * @version v1.0 
  * @date    18-July-2018
  * @brief   Delay program
  ******************************************************************************
 **/

#include <lpc17xx.h> 
#include "delay.h"

void delay(uint32_t ms)
{
	LPC_SC -> PCONP |= (1<<2) ;
  
    LPC_TIM1 -> PR = 25000-1 ; 																		//25000 , indexing starts from 0 	
																											// 25*10^6*10^-3
	LPC_TIM1 -> TCR = (1<<1) ;  

    LPC_TIM1 -> TCR = (1<<0) ; 
	
	while(LPC_TIM1->TC < ms) ; 
	
	LPC_TIM1 -> TCR = 0x00 ; 

}	
