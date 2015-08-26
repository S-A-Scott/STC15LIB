#include "main.h"
#include "timeout.h"
#include "lcd12864.h"

unsigned char code First_line[]  = "first line";
unsigned char code Second_line[] = "second line";
unsigned char code Third_line[]  = "thrid line";
unsigned char code Fourth_line[] = "fourth line";

void main()
{
	uchar i;
	LCD12864_Init();
	LCD12864_Locate(0, 0);
  	i = 0;
	while (First_line[i] != '\0') {
		LCD12864_Write_Data(First_line[i]);
		i++;
	}
	LCD12864_Locate(1, 0);
	i = 0;
	while (Second_line[i] != '\0') {
		LCD12864_Write_Data(Second_line[i]);
		i++;
	}
	LCD12864_Locate(2, 0);
	i = 0;
	while (Third_line[i] != '\0') {
		LCD12864_Write_Data(Third_line[i]);
		i++;
	}
	LCD12864_Locate(3, 0);
	i = 0;
	while (Fourth_line[i] != '\0') {
		LCD12864_Write_Data(Fourth_line[i]);
		i++;
	}


	while (1)
		;
}

