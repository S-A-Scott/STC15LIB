/*---------------------------------------------------------------*-
   Author        : Spencer Scott
   Email         : spencerscott@gmail.com
   Last modified : 2015-08-11 04:24
   Filename      : tm1650.h
  ---------------------------------------------------------------
   
   - See tm1650.c for details.
-*---------------------------------------------------------------*/
 
#ifndef _TM1650_H
#define _TM1650_H

// ------ Public constants --------------------------------

#define DEFAULT_SETTING 0x48
#define NORMAL_DISPLAY	0x01

// From left to right order
#define DISPLAY_POINT	0x80
#define FIRST_POSITON	0x68
#define SECOND_POSITION 0x6A
#define THIRD_POSITION  0x6C
#define FOURTH_POSITON  0x6E

// ------ Public function prototypes ----------------------

void TM1650_Init(void);
void TM1650_Send(unsigned char CMD, unsigned char DATA);


#endif
