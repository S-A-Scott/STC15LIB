#include "main.h"
#include "timeout.h"
#include "lcd12864.h"
#include "hc_sr04.h"
#include "pwm.h"
#include "uart.h"
#include "adc.h"
#include "tm1650.h"

// ------ Public variable declarations --------------------

extern unsigned char code Digital_tube_coding[];

void main()
{
//	TM1650_Write_Byte(0x48);
//	TM1650_Write_Byte(0x01);
//	TM1650_Send_CMD(0x48);
//	TM1650_Send_CMD(0x01);
//	TM1650_Display(0x48, 0x01);
	TM1650_Init();
	TM1650_Send(FIRST_POSITON, Digital_tube_coding[0]);
	TM1650_Send(SECOND_POSITION, Digital_tube_coding[1]);
	TM1650_Send(THIRD_POSITION, Digital_tube_coding[2]);
	TM1650_Send(FOURTH_POSITON, Digital_tube_coding[3]);
	while (1)
		;
}
