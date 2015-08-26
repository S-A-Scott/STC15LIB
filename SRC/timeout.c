/*---------------------------------------------------------------*-
   Author        : Spencer Scott
   Email         : spencerscott@gmail.com
   Last modified : 2015-08-11 04:52
   Filename      : timeout.c
  ---------------------------------------------------------------
   
   - See timeout.h for details.
-*---------------------------------------------------------------*/
 
#include "timeout.h"

void Delay_10us(void)
{
	// Configure Timer 0 as a 16-bit timer
	TMOD &= 0xF0;	// Clear all T0 bits (T1 left unchanged)
	TMOD |= 0x01;	// Set required T0 bits (T1 left unchanged)
	AUXR |= 0x80;	// Set T0x12 bit

	ET0 = 0;		// No interrupts

	// Simple timeout feature - approx 50us
	TH0 = T_10us_H;
	TL0 = T_10us_L;
	TF0 = 0;
	TR0 = 1;

	while (!TF0);
	TR0 = 0;
}

void Delay_50us(void)
{
	// Configure Timer 0 as a 16-bit timer
	TMOD &= 0xF0;	// Clear all T0 bits (T1 left unchanged)
	TMOD |= 0x01;	// Set required T0 bits (T1 left unchanged)
	AUXR |= 0x80;	// Set T0x12 bit

	ET0 = 0;		// No interrupts

	// Simple timeout feature - approx 50us
	TH0 = T_50us_H;
	TL0 = T_50us_L;
	TF0 = 0;
	TR0 = 1;

	while (!TF0);
	TR0 = 0;
}
void Delay_500us(void)
{
	// Configure Timer 0 as a 16-bit timer
	TMOD &= 0xF0;	// Clear all T0 bits (T1 left unchanged)
	TMOD |= 0x01;	// Set required T0 bits (T1 left unchanged)
	AUXR |= 0x80;	// Set T0x12 bit

	ET0 = 0;		// No interrupts

	// Simple timeout feature - approx 500us
	TH0 = T_500us_H;
	TL0 = T_500us_L;
	TF0 = 0;
	TR0 = 1;

	while (!TF0);
	TR0 = 0;
}
void Delay_1ms(void)
{
	// Configure Timer 0 as a 16-bit timer
	TMOD &= 0xF0;	// Clear all T0 bits (T1 left unchanged)
	TMOD |= 0x01;	// Set required T0 bits (T1 left unchanged)
	AUXR |= 0x80;	// Set T0x12 bit

	ET0 = 0;		// No interrupts

	// Simple timeout feature - approx 1ms
	TH0 = T_1ms_H;
	TL0 = T_1ms_L;
	TF0 = 0;
	TR0 = 1;

	while (!TF0);
	TR0 = 0;
}
void Delay_5ms(void)
{
	// Configure Timer 0 as a 16-bit timer
	TMOD &= 0xF0;	// Clear all T0 bits (T1 left unchanged)
	TMOD |= 0x01;	// Set required T0 bits (T1 left unchanged)
	AUXR |= 0x80;	// Set T0x12 bit

	ET0 = 0;		// No interrupts

	// Simple timeout feature - approx 5ms
	TH0 = T_5ms_H;
	TL0 = T_5ms_L;
	TF0 = 0;
	TR0 = 1;

	while (!TF0);
	TR0 = 0;
}
void Delay_10ms(void)
{
	// Configure Timer 0 as a 16-bit timer
	TMOD &= 0xF0;	// Clear all T0 bits (T1 left unchanged)
	TMOD |= 0x01;	// Set required T0 bits (T1 left unchanged)
	AUXR |= 0x80;	// Set T0x12 bit

	ET0 = 0;		// No interrupts

	// Simple timeout feature - approx 10ms
	TH0 = T_10ms_H;
	TL0 = T_10ms_L;
	TF0 = 0;
	TR0 = 1;

	while (!TF0);
	TR0 = 0;
}
void Delay_15ms(void)
{
	// Configure Timer 0 as a 16-bit timer
	TMOD &= 0xF0;	// Clear all T0 bits (T1 left unchanged)
	TMOD |= 0x01;	// Set required T0 bits (T1 left unchanged)
	AUXR |= 0x80;	// Set T0x12 bit

	ET0 = 0;		// No interrupts

	// Simple timeout feature - approx 15ms
	TH0 = T_15ms_H;
	TL0 = T_15ms_L;
	TF0 = 0;
	TR0 = 1;

	while (!TF0);
	TR0 = 0;
}
void Delay_20ms(void)
{
	// Configure Timer 0 as a 16-bit timer
	TMOD &= 0xF0;	// Clear all T0 bits (T1 left unchanged)
	TMOD |= 0x01;	// Set required T0 bits (T1 left unchanged)
	AUXR |= 0x80;	// Set T0x12 bit

	ET0 = 0;		// No interrupts

	// Simple timeout feature - approx 20ms
	TH0 = T_20ms_H;
	TL0 = T_20ms_L;
	TF0 = 0;
	TR0 = 1;

	while (!TF0);
	TR0 = 0	;
}
void Delay_50ms(void)
{
	// Configure Timer 0 as a 16-bit timer
	TMOD &= 0xF0;	// Clear all T0 bits (T1 left unchanged)
	TMOD |= 0x01;	// Set required T0 bits (T1 left unchanged)
	AUXR |= 0x80;	// Set T0x12 bit

	ET0 = 0;		// No interrupts

	// Simple timeout feature - approx 50ms
	TH0 = T_50ms_H;
	TL0 = T_50ms_L;
	TF0 = 0;
	TR0 = 1;

	while (!TF0);
	TR0 = 0;
}

void Delay_500ms(void)
{
	int i = 0;
	for (; i < 500; i++)
		Delay_1ms();
}

void Delay_1s(void)
{
	int i = 0;
	for (; i < 1000; i++)
		Delay_1ms();
}


void Delay_1us(void)
{
	_nop_();
}

void Delay_2us(void)
{
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}

void Delay_3us(void)
{
	Delay_1us();
	Delay_1us();
	Delay_1us();
}

void Delay_4us(void)
{
	Delay_1us();
	Delay_1us();
	Delay_1us();
	Delay_1us();
}

void Delay_5us(void)
{
	Delay_1us();
	Delay_1us();
	Delay_1us();
	Delay_1us();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}
