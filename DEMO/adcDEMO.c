#include "main.h"
#include "timeout.h"
#include "lcd12864.h"
#include "hc_sr04.h"
#include "pwm.h"
#include "uart.h"
#include "adc.h"
#include "utility.h"

void main()
{
	unsigned char data_H;
	unsigned char data_L;
	unsigned int raw_data;
	double result;
	unsigned char buf[10];
	UART1_Init();
	ADC_Init(0xFF);
	while (1) {
		raw_data = ADC_Get_10Bit_Result(5);
		result = raw_data / 1024.0 * 5;
		bzero(buf, 10);
		sprintf(buf, "%f", result);
		UART1_Send_String(buf);
		
//		raw_data = ADC_Get_Result(5);
//		data_H = raw_data >> 8;
//		data_L = raw_data;
//		UART1_Send_Char(data_H);
//		UART1_Send_Char(data_L);
		Delay_1s();	
	}
}
