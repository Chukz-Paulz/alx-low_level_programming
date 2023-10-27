#include "stdio.h"
#include "main.h"

/**
 * get_endianness - checks if a machine is little or big endian
 * Repeatation of project 0x14 Bit manipulation
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	/*Variable Declaration*/
	unsigned int z = 1;
	char *a = (char *) &z;

	/*return value of a*/
	return (*a);
}


