/**
  ******************************************************************************
  * @file    lcd.h 
  * @author  Aditi Bhatnagar
  * @version v2.0 - 16x2 LCD  
  * @date    
  * @brief   16x2 LCD header file
  ******************************************************************************
 **/


#ifndef _lcd_h
#define _lcd_h

#include "LPC17xx.h"                    // Device header
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void LCDcomm(unsigned char cmmd) ; 
void LCDdata(unsigned char data) ; 
void LCD(char array[])  ;
void lcd (unsigned int m) ; 
void LCDd( int a) ; 
void LCDf(float h) ; 
void clear(unsigned char a) ; 
void LCD_INIT(void);

#endif 
