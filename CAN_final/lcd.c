/**
  ******************************************************************************
  * @file    lcd.c 
  * @author  Aditi Bhatnagar
  * @version v2.0 - 16x2 LCD  
  * @date    
  * @brief   16x2 LCD header file
  ******************************************************************************
 **/

#include "lcd.h" 
#include "delay.h"

void LCD_INIT()
{
LPC_GPIO2->FIODIR = (1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7);

	LCDcomm(0x02);      //returns cursor to home
	LCDcomm(0x28);      //set 4bit mode 2 line interface
	LCDcomm(0x0E);      //display on cursor on
	LCDcomm(0x01);      // clears the display including DDRAM contents
	LCDcomm(0x06);      //entry mode set
	LCDcomm(0x80);     //force cursor to beginning of first row
	delay(100);
}
int g; 
void LCDcomm(unsigned char cmmd) // For printing commands
{
	unsigned char a,b;
	a = cmmd & 0xF0;     //sending the upper bits and masking the lower bits
	LPC_GPIO2->FIOPIN0 = (a | 0x08); // RS=0 and EN=1, write=0
	delay(10);
	LPC_GPIO2->FIOPIN0 &= ~(1<<3); //EN=0
	
	b = cmmd & 0x0F;// masking the upper bits
	b = (b<<4);     //sending the lower bits by shifting
	LPC_GPIO2->FIOPIN0 = (b | 0x08);
  delay(10);
	LPC_GPIO2->FIOPIN0 &= ~(1<<3); //EN=0
}

void LCDdata(unsigned char data)  //For printing data
{
	
	
	unsigned char c,d;
	c = data & 0xF0;
	LPC_GPIO2->FIOPIN0  =( c | 0x0C);//RS=1 and EN=1 ,write=0
	delay(10);
	LPC_GPIO2->FIOPIN0 &= ~(1<<3);
	
	d = data & 0x0F;
	d= (d<<4);
	LPC_GPIO2->FIOPIN0 = (d | 0x0C);
	delay(10);
	LPC_GPIO2->FIOPIN0 &= ~(1<<3);
	
}

void LCD(char array[])  //For sending character string
{
	int i=0; 
	for(i=0 ; array[i]!= '\0'; i++)
	{
		LCDdata(array[i]);
		
	}
}

void lcd (unsigned int m)
{
	uint8_t i=0, r,p  ;
	int8_t j ; 
	char str[100] ;	
	if(m==0)
	{ str[i] = '0' ;
		i++ ;
		str[i]= '\0' ;
	}
	while(m!=0)
	{
		r=m%10 ;
		str[i++] = r+ '0' ;
		m=m/10 ;
		 
	}
	str[i++] = '\0' ;
	p=strlen(str) ; 
	for(j=p-1 ; j>=0 ; j--)
	LCDdata(str[j]) ;

}



