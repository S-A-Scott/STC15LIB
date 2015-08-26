/*---------------------------------------------------------------*-
   Author        : Spencer Scott
   Email         : spencerscott@gmail.com
   Last modified : 2015-08-11 04:24
   Filename      : pcf8591.h
  ---------------------------------------------------------------
   
   - See pcf8591.c for details.
-*---------------------------------------------------------------*/
 
#ifndef _PCF8591_H
#define _PCF8591_H


// ------ Public function prototypes ----------------------

unsigned char PCF8951_Get_ADC_Result(unsigned char CHANNEL);
void PCF8951_DA_Conversion(unsigned char VAL);

#endif
