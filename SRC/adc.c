/*---------------------------------------------------------------*-
   Author        : Spencer Scott
   Email         : spencerscott@gmail.com
   Last modified : 2015-08-11 04:28
   Filename      : adc.c
  ---------------------------------------------------------------
   
   8-Channel(from P0.0 to P0.7)
   10-bit high-speed A/D Convertion routine
-*---------------------------------------------------------------*/
 
#include <stdio.h>
#include <intrins.h>
#include "main.h"
#include "timeout.h"

#include "adc.h"

void ADC_Init(unsigned char CHANNEL)
{
	P1ASF = CHANNEL;
	ADC_RES = 0;
	ADC_CONTR = ADC_POWER | ADC_SPEED_540;
	Delay_10us();		// ADC power on and delay
}

unsigned int ADC_Get_10Bit_Result(unsigned char CHANNEL)
{
	unsigned char temp1 = 0;
	unsigned	char temp2 = 0;
	unsigned int result = 0;
	ADC_CONTR = ADC_POWER | ADC_SPEED_540 | ADC_START | CHANNEL;
	_nop_();	// Must wait before inquiry
	_nop_();
	_nop_();
	_nop_();
	while (!(ADC_CONTR & ADC_FLAG))
		;			// Wait complete bit
	ADC_CONTR &= ~ADC_FLAG;
	temp1 = ADC_RES;
	temp2 = ADC_RESL & 0x03;
	result = (unsigned int)temp1 * 4 + temp2;
	
	return result;
}

unsigned char ADC_Get_8Bit_Result(unsigned char CHANNEL)
{
	ADC_CONTR = ADC_POWER | ADC_SPEED_540 | ADC_START | CHANNEL;
	_nop_();	// Must wait before inquiry
	_nop_();
	_nop_();
	_nop_();
	while (!(ADC_CONTR & ADC_FLAG))
		;			// Wait complete bit
	ADC_CONTR &= ~ADC_FLAG;
	return ADC_RES;
}
