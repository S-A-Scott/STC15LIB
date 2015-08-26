/*---------------------------------------------------------------*-
   Author        : Spencer Scott
   Email         : spencerscott@gmail.com
   Last modified : 2015-08-11 04:15
   Filename      : timeout.h
  ---------------------------------------------------------------

   Simple timeout delays for STC serial mcu based on T0.

   In Microsecond level timeout delays, I have considered 
   function overhead, and all the functions have tested by
   the oscilloscope.
-*---------------------------------------------------------------*/
 
#ifndef _TIMEOUT_H
#define _TIMEOUT_H

#include "main.h"

// ------ Public constants --------------------------------

/*---------------------------------------------------------------*-
 * 							The Hardware timeout
-*---------------------------------------------------------------*/

// Timer T_ values for use in simple (hardware) timeout
// Timer are 16-bit, manual reload
//
// NOTE: These macros are portable and timings are *PRECISE*
//       The time-delayed functions are tested with oscilloscope

// Define initial Timer0 / Timer1 values for 10us delay
#ifdef _USE_12M
#define T_10us_H	0xFF
#define T_10us_L	0xB8
#else
#define T_10us_H	0xFF
#define T_10us_L	0xBE
#endif

// Define initial Timer0 / Timer1 values for 50us delay
#define T_50us		(65536 - (uint)((OSC_FREQ / 26000) / (OSC_PER_INST)))
#define T_50us_H	(T_50us / 256)
#define T_50us_L	(T_50us % 256)

// Define initial Timer0 / Timer1 values for 500us delay
#define T_500us		(65536 - (uint)(OSC_FREQ / (OSC_PER_INST * 2000)))
#define T_500us_H	(T_500us / 256)
#define T_500us_L	(T_500us % 256)

// Define initial Timer0 / Timer1 values for 1ms delay
#define T_1ms		(65536 - (uint)(OSC_FREQ / (OSC_PER_INST * 1000)))
#define T_1ms_H		(T_1ms / 256)
#define T_1ms_L		(T_1ms % 256)


// Define initial Timer0 / Timer1 values for 5ms delay
#define T_5ms		(65536 - (uint)(OSC_FREQ / (OSC_PER_INST * 200)))
#define T_5ms_H	(T_5ms / 256)
#define T_5ms_L	(T_5ms % 256)

// Define initial Timer0 / Timer1 values for 10ms delay
#define T_10ms		(65536 - (uint)(OSC_FREQ / (OSC_PER_INST * 100)))
#define T_10ms_H	(T_10ms / 256)
#define T_10ms_L	(T_10ms % 256)

// Define initial Timer0 / Timer1 values for 15ms delay
#define T_15ms		(65536 - (uint)(OSC_FREQ / (OSC_PER_INST * 67)))
#define T_15ms_H	(T_15ms / 256)
#define T_15ms_L	(T_15ms % 256)

// Define initial Timer0 / Timer1 values for 20ms delay
#define T_20ms		(65536 - (uint)(OSC_FREQ / (OSC_PER_INST * 50)))
#define T_20ms_H	(T_20ms / 256)
#define T_20ms_L	(T_20ms % 256)

// Define initial Timer0 / Timer1 values for 50ms delay
#define T_50ms		(65536 - (uint)(OSC_FREQ / (OSC_PER_INST * 20)))
#define T_50ms_H	(T_50ms / 256)
#define T_50ms_L	(T_50ms % 256)

// ------ Public function prototypes ----------------------

// *NOTE*: Delay 1 to 5 us is specified for 11.0592M Oscillator frequency, 1T instruction set
//         There are unportable
void Delay_1us(void);
void Delay_2us(void);
void Delay_3us(void);
void Delay_4us(void);
void Delay_5us(void);

void Delay_10us(void);
void Delay_50us(void);
void Delay_500us(void);
void Delay_1ms(void);
void Delay_5ms(void);
void Delay_10ms(void);
void Delay_15ms(void);
void Delay_20ms(void);
void Delay_50ms(void);
void Delay_500ms(void);
void Delay_1s(void);

#endif
