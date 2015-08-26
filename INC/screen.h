/*---------------------------------------------------------------*-
   Author        : Spencer Scott
   Email         : spencerscott@gmail.com
   Last modified : 2015-08-11 04:24
   Filename      : screen.h
  ---------------------------------------------------------------
   
   - See screen.c for details.
-*---------------------------------------------------------------*/
 
#ifndef _SCREEN_H
#define _SCREEN_H

// ------ Public constants --------------------------------

// *NOTE* This marco decides which uart will be used
//#define USE_UART1
#define USE_UART2

#define U1_VOLTAGE  0
#define U2_VOLTAGE  1
#define I2_CURRENT  2

// ------ Public function prototypes ----------------------

void SCREEN_Send_CMD(unsigned char *CMD);
void SCREEN_Display(unsigned char *MESSAGE);
void SCREEN_Display_AD(unsigned char REGION, double MESSAGE);

#endif
