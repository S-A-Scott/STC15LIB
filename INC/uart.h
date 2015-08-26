/*---------------------------------------------------------------*-
   Author        : Spencer Scott
   Email         : spencerscott@gmail.com
   Last modified : 2015-08-11 04:24
   Filename      : uart.h
  ---------------------------------------------------------------
   
   - See uart.c for details.
-*---------------------------------------------------------------*/
 
#ifndef _UART_H
#define _UART_H

// ------ Public constants --------------------------------

#define S2RI  0x01			// S2CON.0
#define S2TI  0x02			// S2CON.1

#define BAUD_RATE_9600 
//#define BAUD_RATE_115200	

// ------ Public function prototypes ----------------------

void UART1_Init(void);
void UART2_Init(void);
void UART1_Send_Char(unsigned char CHAR);
void UART2_Send_Char(unsigned char CHAR);
char UART1_Send_String(unsigned char *STR);
char UART2_Send_String(unsigned char *STR);
void UART1_Bzero(void);
void UART2_Bzero(void);

#endif
