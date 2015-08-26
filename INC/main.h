/*---------------------------------------------------------------*-
   Author        : Spencer Scott
   Email         : spencerscott@gmail.com
   Last modified : 2015-08-11 04:25
   Filename      : main.h
  ---------------------------------------------------------------
   
   Project Header for this project. 
-*---------------------------------------------------------------*/
 
/*---------------------------------------------------------------*-
 * WILL NEED TO EDIT THIS SECTION FOR EVERY PROJECT
-*---------------------------------------------------------------*/

#ifndef _MAIN_H
#define _MAIN_H

/*---------------------------------------------------------------*-
 * Must include the appropriate microcontroller header file here 
-*---------------------------------------------------------------*/
#include <STC15F2K60S2.H>
#include <stdio.h>			// declare sprintf()
#include <intrins.h>		// declare _nop_()


/*---------------------------------------------------------------*-
 * Oscillator frequency (in Hz) e.g 11059200UL
-*---------------------------------------------------------------*/
//#define OSC_FREQ	12000000UL
//#define _USE_12M
#define OSC_FREQ	11059200UL

/*---------------------------------------------------------------*-
 * Number of oscillations per instruction (12, etc) 
 * 12 - original 8051 / 8052
 * 6  - Various Infineon and Philips devices, etc
 * 4  - Dallas 320, 520 etc
 * 1  - Dallas 420, etc	
-*---------------------------------------------------------------*/
#define OSC_PER_INST	1


/*---------------------------------------------------------------*-
 * 							Typedefs 
-*---------------------------------------------------------------*/
typedef unsigned char uchar;
typedef unsigned int  uint;
typedef unsigned long ulong;


/*---------------------------------------------------------------*-
 * 							Interrupts
-*---------------------------------------------------------------*/
#define INTERRUPT_Timer_0_Overflow 1
#define INTERRUPT_Timer_1_Overflow 3
#define INTERRUPT_UART_1_Overflow  4
#define INTERRUPT_Timer_2_Overflow 5
#define INTERRUPT_UART_2_Overflow  8

#endif
