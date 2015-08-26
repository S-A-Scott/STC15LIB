/*---------------------------------------------------------------*-
   Author        : Spencer Scott
   Email         : spencerscott@gmail.com
   Last modified : 2015-08-11 04:33
   Filename      : hc_sr04.c
  ---------------------------------------------------------------
   
   Simple ultrasonic module library
-*---------------------------------------------------------------*/
 
#include "main.h"
#include "timeout.h"
#include "port.h"

#include "hc_sr04.h"

// ------ Private function prototypes ---------------------

static void HC_SR04_Trigger(void);

/*---------------------------------------------------------------*-
 * HC_SR04_Init()
 * 
 * Initialization function for HC_SR04 library
-*---------------------------------------------------------------*/
void HC_SR04_Init(void)
{
	Echo_pin = 1;	// Sets Echo pin as input for receiving echo
	Trig_pin = 0;	// Sets Trig pin as output for sending tirgger
	TMOD = 0x10;	// Sets timer 1 as mode 1 16-bit timer
	EA  = 1;
	ET1 = 1;
	TR1 = 0;
	TF1 = 0;
}


/*---------------------------------------------------------------*-
 * HC_SR04_Trigger()
 * 
 * Gives 20us width for the trigger pulse
-*---------------------------------------------------------------*/
void HC_SR04_Trigger(void)
{
	Trig_pin = 1;	// Starts the trigger pulse
	Delay_10us();
	Delay_10us();	
	Trig_pin = 0;	// ends the trigger pulse
}


/*---------------------------------------------------------------*-
 * HC_SR04_Get_Distance()
 * 
 * Returns the data measured by sensor
 * NOTE: the value is 10 x magnification than the original
 * e.g.	 original         return value
 *	     12.3cm           123cm
-*---------------------------------------------------------------*/
unsigned int
HC_SR04_Get_Distance(void)
{
	unsigned int time, distance;
	// Prepares for measuring hight input IO duration
	TH1 = 0;
	TL1 = 0;
	TF1 = 0;
	
	HC_SR04_Trigger();
	while (!Echo_pin)
		;
	TR1 = 1;	// Starts timer 1
	while (Echo_pin)
		;
	TR1 = 0;	// Ends timer 1

	if (TF1) {
		distance = 9999;
	} else {
		time = TH1 * 256 + TL1;
		//distance = time * 344 / 2 / 1000000 * 100; // (cm)
		distance = time *  0.172 + 0.5;		// 10 x magnification
	}
	return distance;
}
