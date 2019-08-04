/**
  ******************************************************************************
  * @file    CAN.h 
  * @author  Pranjal Shrivastava
  * @version v2.0 - CAN  
  * @date    20-July-2019
  * @brief   CAN Header File
  ******************************************************************************
 **/


#ifndef _CAN_H
#define _CAN_H

#include "LPC17xx.h"                    // Device header

#define AF_OFF			0x01
#define AF_BYPASS		0x02
#define AF_ON			0x00
#define AF_FULLCAN		0x04

/* Identifiers for EXP STD, GRP STD */
#define EXP_STD_ID		0x100
#define GRP_STD_ID		0x100

#define OK 1 
#define NOT_OK 0 

typedef struct {
	
	
	uint32_t FRAME ;  				// Bits 19-16: DLC - Data Length Count
						       // Bit 30: Set for a RTR message
						      // Bit 31: Set for a 29-bit, Extended ID message
	uint32_t MSG_ID ;    		  // CAN Message ID (11-bit or 29-bit)
	uint32_t Data_A ; 		 // CAN Message Data Bytes 0-3
	uint32_t Data_B ;  	 	// CAN Message Data Bytes 4-7

} CAN_MSG_type;


void init_CAN(void)  ;
uint8_t CAN1_Tx (CAN_MSG_type* tx_data) ;
uint8_t CAN2_Tx (CAN_MSG_type* tx_data) ;
//void do_CAN1_rx(void) ; 
//void do_CAN2_rx(void) ;
//void setup_LUT(void) ; 
void CONFIG_CAN_FILTER_MODE (uint8_t mode) ; 


#endif

