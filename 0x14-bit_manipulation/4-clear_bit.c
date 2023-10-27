#include <stdio.h>
#include "main.h"
/**
 * clear_bit - sets bit to 0 at given index
 * @n: pointer to unsigned long int
 * @index: index to set to 0
 *
 * Return: 1 if succeed -1 if failed
 * Repeatation of project 0x14 Bit manipulation
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	/*Declaration*/
	unsigned long int size_it, maskit;

	size_it = sizeof(*n) * 8 - 1;

	if (index > size_it)
		return (-1);

	maskit = 1 << index;

	*n = *n & ~maskit;

	/*On successful, Return 1*/
	return (1);
}
