#include "main.h"
#include "timeout.h"
#include "lcd12864.h"
#include "hc_sr04.h"
#include "pwm.h"

void main()
{
	PWM0_Init();
	PWM1_Init();
	PWM0_Set(0xff);
	PWM1_Set(0x80);
}
