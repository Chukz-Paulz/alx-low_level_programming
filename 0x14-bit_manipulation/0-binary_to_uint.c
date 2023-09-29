#include "main.h"
#include <stdio.h>
/**
 * binary_to_uint - convert binary string to decimal
 * @b: binary string
 *
 * Return: decimal (unsigned int)
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int a;
	unsigned int decimal;

	for (decimal = 0, a = 0; b[a] != '\0'; a++)
	{
		/*if condition statements*/
		if (b[a] == '1')
			decimal = (decimal << 1) | 1;
		else if (b[a] == '0')
			decimal <<= 1;
		else if (b[a] != '0' && b[a] != '1')
			/*return value*/
			return (0);
	}

	/*Return decimal*/
	return (decimal);
}
