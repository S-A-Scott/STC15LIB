#include "main.h"
#include "timeout.h"
#include "lcd12864.h"
#include "hc_sr04.h"
#include "pwm.h"
#include "uart.h"
#include "utility.h"
#include "screen.h"


// ------ Public variable declarations -------------------
extern uchar xdata UART1_data_received[];
extern uchar xdata UART2_data_received[];

void main()
{
	UART1_Init();
	UART2_Init();
	
	SCREEN_Send_CMD("page button2");
	while (1) {
		SCREEN_Display("hello, world");
		Delay_1s();	
	}
}

