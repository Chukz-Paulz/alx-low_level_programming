#include "main.h"
/**
 * flip_bits - returns the number of bits you would need to flip
 * to get from one number to another
 * @n: the first number
 * @o: the second number
 * Return: the number of flipped bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int o)
{
	unsigned int xor = n ^ o;
	int count = 0;
	int j;
	unsigned long int current;

	if (!n || !o)
		return (0);

	for (j = 63; j >= 0; j--)
	{
		current = exclusive >> j;
		if (current & 1)
			count++;
	}

	return (count);
}

