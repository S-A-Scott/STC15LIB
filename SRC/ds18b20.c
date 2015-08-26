#include "main.h"
#include "timeout.h"

#include "ds18b20.h"

// ------ Private function prototypes ---------------------

static void DS18B20_Init(void);



void DS18B20_Init(void)
{
	DS_data_pin = 0;
	Delay_500us();

	DS_data_pin = 1;

}
