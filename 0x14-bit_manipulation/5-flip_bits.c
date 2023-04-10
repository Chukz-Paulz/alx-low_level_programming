#include "main.h"
/**
 * flip_bits - returns the number of bits you would need to flip
 * to get from one number to another
 * @n: the first number
 * @m: the second number
 * Return: the number of flipped bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int o)
{
	unsigned int xor = n ^ o;
	int count = 0;

	if (!n || !o)
		return (0);
	while (xor)
	{
		if (xor & 1)
			count++;
		xor = xor >> 1;
	}
	return (count);
}
