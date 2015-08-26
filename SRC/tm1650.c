/*---------------------------------------------------------------*-
   Author        : Spencer Scott
   Email         : spencerscott@gmail.com
   Last modified : 2015-08-11 04:52
   Filename      : tm1650.c
  ---------------------------------------------------------------
    
      
-*---------------------------------------------------------------*/
 
#include "main.h"
#include "timeout.h"
#include "port.h"

#include "tm1650.h"

// ------ Public variable definitions ---------------------

unsigned char code Digital_tube_coding[] = {
	0x3F, 0x06, 0x5B, 0x4F,
	0x66, 0x6D, 0x7D, 0x07,
	0x7F, 0x6F, 0x77, 0x7C,
	0x39, 0x5E, 0x79, 0x71,
};

// ------ Private function prototypes ---------------------

static void TM1650_Start(void);
static void TM1650_Stop(void);
static void TM1650_Response(void);
static void Delay_us(unsigned char TIME);
static void TM1650_Write_Byte(unsigned char DATA);


/*---------------------------------------------------------------*-
 * TM1650_Start()
 * 
 * Send start condition 
-*---------------------------------------------------------------*/
void TM1650_Start(void)
{
	SCL = 1;
	SDA = 1;
	Delay_5us();
	SDA = 0;
	Delay_5us();
	SCL = 0;
	Delay_5us();
}

/*---------------------------------------------------------------*-
 * TM1650_Stop();
 * 
 * Send stop condition
-*---------------------------------------------------------------*/
void TM1650_Stop(void)
{
	SCL = 0;
	SDA = 0;
	Delay_5us();
	SCL = 1;
	Delay_5us();
	SDA = 1;
	Delay_5us();
}


/*---------------------------------------------------------------*-
 * TM1650_ACK()
 * 
 * Make sure the slave has received the data
-*---------------------------------------------------------------*/
void TM1650_ACK()
{
	SDA = 0;
	SCL = 1;
	Delay_5us();
	SCL = 0;
	SDA = 1;
}


/*---------------------------------------------------------------*-
 * TM1650_Write_Byte()
 * 
 * Send one byte data to slave
-*---------------------------------------------------------------*/
void TM1650_Write_Byte(unsigned char DATA)
{
	unsigned char i;
	for (i = 0; i < 8; i++) {
		if ((DATA & 0x80) == 0)
			SDA = 0;
		else
			SDA = 1;
		DATA <<= 1;
		SCL = 0;
		Delay_5us();
		SCL = 1;
		Delay_5us();
		SCL = 0;
		Delay_5us();
	}
}

void TM1650_Init(void)
{
	TM1650_Send(DEFAULT_SETTING, NORMAL_DISPLAY);
}

/*---------------------------------------------------------------*-
 * TM1650_Display()
 * 
 * Display the number on the specified postion or Send
 * initialization commands.
-*---------------------------------------------------------------*/
void TM1650_Send(unsigned char CMD, unsigned char DATA)
{
	TM1650_Start();
	TM1650_Write_Byte(CMD);	
	TM1650_ACK();
	TM1650_Write_Byte(DATA);
	TM1650_ACK();
	TM1650_Stop();
}
