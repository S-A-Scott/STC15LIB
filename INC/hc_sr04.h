/*---------------------------------------------------------------*-
   Author        : Spencer Scott
   Email         : spencerscott@gmail.com
   Last modified : 2015-08-11 04:12
   Filename      : hc_sr04.h
  ---------------------------------------------------------------

   - See hc_sr04.c for details
-*---------------------------------------------------------------*/

#ifndef _HC_SR04H
#define _HC_SR04H

// ------ Public function prototypes ----------------------

void HC_SR04_Init(void);
unsigned int HC_SR04_Get_Distance(void);

#endif
