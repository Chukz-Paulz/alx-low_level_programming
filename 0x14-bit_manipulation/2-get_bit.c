#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * @n: number to search
 * @index: index of the bit
 *
 * Return: value of the bit
 * Repeatation of project 0x14 Bit manipulation
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int b;

		if (index > 63)
			return (-1);

		b = (n >> index) & 1;
	/*returns value*/
	return (b);
}
