#include "main.h"
#include "timeout.h"
#include "lcd12864.h"
#include "hc_sr04.h"

unsigned char First_line[]  = "000.0cm";
unsigned char code Second_line[] = "second line           ";
unsigned char code Third_line[]  = "thrid line            ";
unsigned char code Fourth_line[] = "fourth line           ";

unsigned char code table[] = "0123456789";

void main()
{
	uchar i = 0;
	unsigned int x = 0;
	unsigned int distance = 0;
	LCD12864_Init();
	HC_SR04_Init();
	while (1) {
		i = 0;
		LCD12864_Locate(0, 0);
	  	distance = HC_SR04_Get_Distance();
		First_line[0] = table[distance/1000];
		First_line[1] = table[distance%1000/100];
		First_line[2] = table[distance%100/10];
		First_line[4] = table[distance%10];
		while (First_line[i] != '\0') {
			LCD12864_Write_Data(First_line[i]);
			i++;
		}
		for (x = 0; x < 1000; x++)
			Delay_1ms(); 
	}
}
