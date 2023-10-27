#include <stdio.h>
#include "main.h"
/**
 * print_binary - prints decimal as binary
 * @n: long integer
 * Repeatation of project 0x14 Bit manipulation
 */

void print_binary(unsigned long int n)
{
	/*Variable declaration*/
	signed long int size;
	char z;
	int flag;

	size = sizeof(n) * 8 - 1;

	/*Condition statements*/
	if (n == 0)
	{
		printf("0");
		return;
	}

	if (n == 1)
	{
		printf("1");
		return;
	}

	flag = 0;

	while (size >= 0)
	{
		z = (n >> size) & 1;

		if (flag == 1)
			putchar(z + '0');
		else
		{
			if (z == 1)
			{
				putchar(z + '0');
				flag = 1;
			}
		}

		size -= 1;
	}
}

