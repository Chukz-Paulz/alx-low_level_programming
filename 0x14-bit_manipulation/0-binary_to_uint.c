#include "main.h"
#include <stdio.h>
/**
 * binary_to_uint - This converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number, or 0 if an error occurs
 * Repeatation of project 0x14 Bit manipulation
 */
unsigned int binary_to_uint(const char *b)
{
	/*Variable Declaration*/
	int a;
	unsigned int decimal_val = 0;

	if (!b)
	return (0);
	/* For Loop*/
	for (a = 0; b[a]; a++)
	{
		if (b[a] != '0' && b[a] != '1')
		return (0);
		decimal_val = decimal_val * 2 + (b[a] - '0');
	}
	/*Return value*/

	return (decimal_val);
}

