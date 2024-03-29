#include <stdio.h>
#include "main.h"
/**
 * set_bit - sets a bit to 1 at a given index
 * @n: pointer to integer
 * @index: index to set to 1
 *
 * Return: 1 if succeeded of -1 if failed
 * Repeatation of project 0x14 Bit manipulation
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	/*Variable declaration*/
	unsigned long int size_it;
	unsigned long int maskit;

	size_it = sizeof(*n) * 8 - 1;

	if (index > size_it)
		return (-1);

	maskit = 1 << index;

	*n = maskit | *n;

	/*Return Value of 1*/

	return (1);
}

