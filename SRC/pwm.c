/*---------------------------------------------------------------*-
   Author        : Spencer Scott
   Email         : spencerscott@gmail.com
   Last modified : 2015-08-11 04:45
   Filename      : pwm.c
  ---------------------------------------------------------------
   
   Use *INNER* Pulse Width Modulator to generator PWM.

   The frequency of the output depends on the source for the
   PCA timer. I didn't give the interface for modifing clock
   input source, if necessary, you can modify CMOD register.
-*---------------------------------------------------------------*/
 
#include "main.h"

#include "pwm.h"

/*---------------------------------------------------------------*-
 * PWM0_Init(void)
 * 
 * Initialization function for PWM library
 * NOTE: Duty cycle = DUTY / 100H
 * WARNING: *DON'T* assign 0 to DUTY
-*---------------------------------------------------------------*/
void PWM0_Init(unsigned char DUTY)
{
	CCON = 0;		// Clears interrupt flag
	CMOD = 0x02;	// Sets PCA timer clock source as FOSC/2
	CL = 0;			// Resets PCA base timer
	CH = 0;

	PCA_PWM0 = 0x00;
	CCAP0L = 256 - DUTY;
	CCAP0H = 256 - DUTY;
	CCAPM0 = 0x42;	// PCA moudle 0 works in 8-bit PWM mode

	CR = 1;			// Starts PCA
}


/*---------------------------------------------------------------*-
 * PWM1_Init(void)
 * 
 * Initialization function for PWM library
 * NOTE: Duty cycle = DUTY / 100H
-*---------------------------------------------------------------*/
void PWM1_Init(unsigned char DUTY)
{
	CCON = 0;		// Clears interrupt flag
	CMOD = 0x02;	// Sets PCA timer clock source as FOSC/2
	CL = 0;			// Resets PCA base timer
	CH = 0;

	PCA_PWM1 = 0x00;	
	CCAP1L = 256 - DUTY;
	CCAP1H = 256 - DUTY;
	CCAPM1 = 0x42;	// PCA moudle 0 works in 8-bit PWM mode

	CR = 1;			// Starts PCA
}


