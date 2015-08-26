/*---------------------------------------------------------------*-
   Author        : Spencer Scott
   Email         : spencerscott@gmail.com
   Last modified : 2015-08-11 04:40
   Filename      : lcd12864.c
  ---------------------------------------------------------------
   
   Parallel interface code for LCD12864.

   Only implement *BASIC* instruction set.
-*---------------------------------------------------------------*/
 
#include "main.h"
#include "timeout.h"
#include "port.h"

#include "lcd12864.h"


/*---------------------------------------------------------------*-
 * LCD12864_Init()
 * 
 * Initialization function for LCD12864 library 
-*---------------------------------------------------------------*/
void LCD12864_Init(void)
{
	LCD12864_PSB = 1;

	LCD12864_Write_CMD(BASIC_INSTRUCTION_SET);	
	Delay_5ms();
	LCD12864_Write_CMD(DISPLAY_CURSOR);	
	Delay_5ms();
	LCD12864_Write_CMD(CLEAR_DISPLAY);
	Delay_5ms();
}


/*---------------------------------------------------------------*-
 * LCD12864_Write_CMD()
 * 
 * Write instruction
-*---------------------------------------------------------------*/
void LCD12864_Write_CMD(unsigned char CMD)
{
	LCD12864_RS = 0;
	LCD12864_RW = 0;
	LCD12864_EN = 0;
	LCD12864_port = CMD;
	Delay_5ms();
	LCD12864_EN = 1;
	Delay_5ms();
	LCD12864_EN = 0;
}


/*---------------------------------------------------------------*-
 * LCD12864_Write_Data()
 * 
 * Write data into display data RAM
-*---------------------------------------------------------------*/
void LCD12864_Write_Data(unsigned char DATA)
{
	LCD12864_RS = 1;
	LCD12864_RW = 0;
	LCD12864_EN = 0;
	LCD12864_port = DATA;
	Delay_5ms();
	LCD12864_EN = 1;
	Delay_5ms();
	LCD12864_EN = 0;
}


/*---------------------------------------------------------------*-
 * LCD12864_Locate()
 * 
 * Locate the display position
-*---------------------------------------------------------------*/
void LCD12864_Locate(unsigned char X, unsigned char Y)
{
	unsigned char pos;
	if (X == 0) {
		X = 0x80;
	} else if (X == 1) {
		X = 0x90;
	} else if (X == 2) {
		X = 0x88;
	} else if (X == 3) {
		X = 0x98;
	}

	pos = X + Y;
	LCD12864_Write_CMD(pos);
}
