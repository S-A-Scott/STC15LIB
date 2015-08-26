#include "main.h"
#include "timeout.h"
#include "lcd12864.h"
#include "hc_sr04.h"
#include "pwm.h"
#include "uart.h"
#include "adc.h"
#include "tm1650.h"
#include "pcf8591.h"


void main()
{
	UART1_Init();
	while (1) {
		//UART1_Send_Char(PCF8951_Get_ADC_Result(2));
		PCF8951_DA_Conversion(0xfe);
		Delay_1s();
	}
}

