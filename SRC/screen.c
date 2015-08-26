#include "main.h"
#include "uart.h"

#include "screen.h"

#ifdef USE_UART1
	#define UART_Send_Char 		UART1_Send_Char
	#define UART_Send_String 	UART1_Send_String
#else
	#define UART_Send_Char 		UART2_Send_Char
	#define UART_Send_String 	UART2_Send_String
#endif

// ------ Private function prototypes ---------------------

static void SCREEN_Send_End(void);

/*---------------------------------------------------------------*-
 * SCREEN_Send_CMD()
 * 
 * Sends corresponding command to the touch screen
-*---------------------------------------------------------------*/
void SCREEN_Send_CMD(unsigned char *CMD)
{
	SCREEN_Send_End();
	UART_Send_String(CMD);
	SCREEN_Send_End();
}


/*---------------------------------------------------------------*-
 * SCREEN_Display()
 * 
 * Displays the user messages on the screen
-*---------------------------------------------------------------*/
void SCREEN_Display(unsigned char *MESSAGE)
{
	unsigned char xdata buf[64];
	sprintf(buf, "t0.txt=t0.txt+\"%s\"", MESSAGE);
	SCREEN_Send_CMD(buf);
}

/*---------------------------------------------------------------*-
 * SCREEN_Display_AD()
 * 
 * Displays the user messages on the screen
-*---------------------------------------------------------------*/
void SCREEN_Display_AD(unsigned char REGION, double MESSAGE)
{
	unsigned char xdata buf[64];
	if (REGION == U1_VOLTAGE) {
		sprintf(buf, "t0.txt=\"%.3fV\"", MESSAGE);
	} else if (REGION == U2_VOLTAGE) {
		sprintf(buf, "t1.txt=\"%.3fV\"", MESSAGE);
	} else if (REGION == I2_CURRENT) {
		sprintf(buf, "t2.txt=\"%.2fA\"", MESSAGE);
	}
	SCREEN_Send_CMD(buf);
}

/*---------------------------------------------------------------*-
 * SCREEN_Send_End()
 * 
 * Appends terminal bytes at the end of string
-*---------------------------------------------------------------*/
void SCREEN_Send_End(void)
{
	UART_Send_Char(0xFF);
	UART_Send_Char(0xFF);
	UART_Send_Char(0xFF);
}


