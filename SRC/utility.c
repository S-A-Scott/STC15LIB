#include "utility.h"

void bzero(unsigned char *STR, unsigned int LENGTH)
{
	int i = 0;
	for (; i < LENGTH; i++)
		STR[i] = 0;
}