#include "main.h"
#include "timeout.h"
#include "lcd12864.h"
#include "hc_sr04.h"
#include "pwm.h"
#include "uart.h"
#include "utility.h"


// ------ Public variable declarations -------------------
extern uchar xdata UART1_data_received[];
extern uchar xdata UART2_data_received[];

void main()
{
	UART1_Init();
	UART2_Init();
	while (1) {
		if (UART1_Send_String(UART2_data_received))
			UART2_Bzero();
//		UART1_Send_String("hello world\n");
//		UART2_Send_String("spencer scott\n");
//		UART2_Send_String(UART2_data_received);
		Delay_1s();	
	}
}