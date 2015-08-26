/*---------------------------------------------------------------*-
   Author        : Spencer Scott
   Email         : spencerscott@gmail.com
   Last modified : 2015-08-11 04:13
   Filename      : lcd12864.h
  ---------------------------------------------------------------

   - See lcd12864.c for details.
-*---------------------------------------------------------------*/
 
#ifndef _LCD12864_H
#define _LCD12864_H

// ------ Public constants --------------------------------

#define CLEAR_DISPLAY			0x01
#define BASIC_INSTRUCTION_SET	0x30
#define EXPAND_INSTRUCTION_SET  0X34
#define DISPLAY_CURSOR			0x0c
#define HIDE_CURSOR				0x08

// ------ Public function prototypes ----------------------

void LCD12864_Init(void);
void LCD12864_Write_CMD(unsigned char CMD);
void LCD12864_Write_Data(unsigned char DATA);
void LCD12864_Locate(unsigned char X, unsigned char Y);

#endif
