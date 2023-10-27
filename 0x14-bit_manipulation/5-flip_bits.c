#include "main.h"
#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 * Repeatation of project 0x14 Bit manipulation
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int a, counter_ = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	/*for loop */
	for (a = 63; a >= 0; a--)
	{
		current = exclusive >> a;
		if (current & 1)
			counter_++;
	}
	/*Return bit count*/
	return (counter_);
}
