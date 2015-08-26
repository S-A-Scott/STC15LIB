#include "port.h"
#include "main.h"
#include "timeout.h"


#include "pcf8591.h"

// ------ Private constants -------------------------------

#define PCF8591_WRITE_ADDRESS 0x90
#define PCF8591_READ_ADDRESS  0x91

// ------ Private function prototypes ---------------------

static void PCF8591_Start(void);
static void PCF8591_Stop(void);
static void PCF8591_ACK(void);
static void PCF8591_NO_ACK(void);
static void PCF8591_Write_Byte(unsigned char);
static unsigned char PCF8591_Read_Byte(void);

/*---------------------------------------------------------------*-
 * PCF8591_Start()
 * 
 * Send start condition 
-*---------------------------------------------------------------*/
void PCF8591_Start(void)
{
	PCF_SCL = 1;
	PCF_SDA = 1;
	Delay_5us();
	PCF_SDA = 0;
	Delay_5us();
	PCF_SCL = 0;
	Delay_5us();
}

/*---------------------------------------------------------------*-
 * PCF8591_Stop();
 * 
 * Send stop condition
-*---------------------------------------------------------------*/
void PCF8591_Stop(void)
{
	PCF_SCL = 0;
	PCF_SDA = 0;
	Delay_5us();
	PCF_SCL = 1;
	Delay_5us();
	PCF_SDA = 1;
	Delay_5us();
}


/*---------------------------------------------------------------*-
 * PCF8591_ACK()
 * 
 * Make sure the slave has received the data
-*---------------------------------------------------------------*/
void PCF8591_ACK()
{
	PCF_SDA = 0;
	PCF_SCL = 1;
	Delay_5us();
	PCF_SCL = 0;
	PCF_SDA = 1;
}

void PCF8591_NO_ACK()
{
	PCF_SDA = 1;
	Delay_5us();
	PCF_SCL = 1;
	Delay_5us();
	PCF_SCL = 0;
	Delay_5us();
}

/*---------------------------------------------------------------*-
 * PCF8591_Write_Byte()
 * 
 * Send one byte data to slave
-*---------------------------------------------------------------*/
void PCF8591_Write_Byte(unsigned char DATA)
{
	unsigned char i;
	for (i = 0; i < 8; i++) {
		if ((DATA & 0x80) == 0)
			PCF_SDA = 0;
		else
			PCF_SDA = 1;
		DATA <<= 1;
		PCF_SCL = 0;
		Delay_5us();
		PCF_SCL = 1;
		Delay_5us();
		PCF_SCL = 0;
		Delay_5us();
	}
}

/*---------------------------------------------------------------*-
 * PCF8591_Read_Byte()
 * 
 * Read one byte data from slave
-*---------------------------------------------------------------*/
unsigned char PCF8591_Read_Byte(void)
{
	unsigned char i = 0;
	unsigned char Data;

	for (i = 0; i < 8; i++) {
		PCF_SCL = 1;
		Delay_5us();
		if (PCF_SDA)
			Data |= 1;
		if (i < 7)
			Data <<= 1;
		PCF_SCL = 0;
		Delay_5us();
	}
	return Data;
}

unsigned char PCF8951_Get_ADC_Result(unsigned char CHANNEL)
{
	unsigned char result;

	PCF8591_Start();
	PCF8591_Write_Byte(PCF8591_WRITE_ADDRESS);
	PCF8591_ACK();
	PCF8591_Write_Byte(0x40 | CHANNEL);
	PCF8591_ACK();
	PCF8591_Stop();

	PCF8591_Start();
	PCF8591_Write_Byte(PCF8591_READ_ADDRESS);
	PCF8591_ACK();
	result = PCF8591_Read_Byte();
	PCF8591_NO_ACK();
	PCF8591_Stop();

	return result;
}


void PCF8951_DA_Conversion(unsigned char VAL)
{
 	PCF8591_Start();
	PCF8591_Write_Byte(PCF8591_WRITE_ADDRESS);
	PCF8591_ACK();
	PCF8591_Write_Byte(0x40);
	PCF8591_ACK();
	PCF8591_Write_Byte(VAL);
	PCF8591_ACK();
	PCF8591_Stop();
}
