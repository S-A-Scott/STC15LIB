#include "main.h"
#include "utility.h"

#include "uart.h"

// ------ Public variable declarations --------------------
extern double Current_of_i2;

// ------ Private variable definitions --------------------

static bit UART1_busy = 0;
static bit UART2_busy = 0;

// ------ Public variable definitions ---------------------
uchar xdata UART1_data_received[64];
uchar UART1_data_counter = 0;

uchar xdata UART2_data_received[64];
uchar UART2_data_counter = 0;

// ------ private variable definitions -------------------- 

#ifdef BAUD_RATE_9600
	#define T2_L 0xE0
	#define T2_H 0xFE
#else
	#define T2_L 0xE8
	#define T2_H 0xFF
#endif

/*---------------------------------------------------------------*-
 * UART1_Init()
 * 
 * Initialization function for UART1 library
-*---------------------------------------------------------------*/
void UART1_Init()
{
	bzero(UART1_data_received, 64);
	SCON  = 0x50;	// 8-bit variable UART
	AUXR |= 0x04;	// Baudrate generator works in 1T mode
	AUXR |= 0x01;	// Choose timer 2 as baudrate generator
	T2L   = T2_L;
	T2H   = T2_H;
	AUXR |= 0x10;	// Enable Timer 2

	ES    = 1;		// Enable UART1 interrupt
	EA    = 1;
}

/*---------------------------------------------------------------*-
 * UART2_Init()
 * 
 * Initialization function for UART2 library
-*---------------------------------------------------------------*/
void UART2_Init()
{
	bzero(UART2_data_received, 64);
	S2CON = 0x50;	// 8-bit variable UART
	AUXR |= 0x04;	// Baudrate generator works in 1T mode
	T2L   = T2_L;
	T2H   = T2_H;
	AUXR |= 0x10;	// Enable Timer 2

	IE2  |= 0x01;	// Enable UART2 interrupt
	EA    = 1;		// Open master interrupt switch
}

void UART1_Bzero(void)
{
	uchar i = 0;
	for (; i < UART1_data_counter; i++)
		UART1_data_received[i] = 0;
	UART1_data_counter = 0;
}

void UART2_Bzero(void)
{
	uchar i = 0;
	for (; i < UART2_data_counter; i++)
		UART2_data_received[i] = 0;
	UART2_data_counter = 0;
}

void UART1_Send_Char(unsigned char CHAR)
{
	while (UART1_busy)
		;
	UART1_busy = 1;
	SBUF = CHAR;		
}

void UART2_Send_Char(unsigned char CHAR)
{
	while (UART2_busy)
		;

	UART2_busy = 1;
	S2BUF = CHAR;
}

char UART1_Send_String(unsigned char *STR)
{
	if (*STR == '\0')
		return 0;
	while (*STR != '\0') {
		UART1_Send_Char(*STR);
		STR++;
	}
	return 1;
}

char UART2_Send_String(unsigned char *STR)
{
	if (*STR == '\0')
		return 0;
	while (*STR != '\0') {
		UART2_Send_Char(*STR);
		STR++;
	}
	return 1;
}

void UART1_Interrupt() interrupt INTERRUPT_UART_1_Overflow using 1
{
	if (RI) {
		RI = 0;
		UART1_data_received[UART1_data_counter++] = SBUF;
	}
	if (TI) {
		TI = 0;
		UART1_busy = 0;
	}
}


void UART2_Interrupt() interrupt INTERRUPT_UART_2_Overflow using 1
{
	if (S2CON & S2RI) {
		S2CON &= ~S2RI;
		UART2_data_received[UART2_data_counter++] = S2BUF;
		if (UART2_data_received[0] == 'a') {
			if ((2.0 - Current_of_i2) > 0.0001)
				Current_of_i2 += 0.05;
			UART2_Bzero();
		}
		else if (UART2_data_received[0] == 'd') {
			if ((Current_of_i2 - 1.0) > 0.0001)
				Current_of_i2 -= 0.05;
			UART2_Bzero();
		}		
	}
	if (S2CON & S2TI) {
		S2CON &= ~S2TI;
		UART2_busy = 0;
	}
}