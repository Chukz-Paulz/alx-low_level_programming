#include <stdio.h>
/** This function concatenates two strings by appending
 * the second string to the end of the first string.
 * The first string is modified in place.
 * The function returns a pointer to the resulting string.
 * */

char *_strcat(char *dest, char *src)
{
	int dest_len = 0;
	int i = 0;
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	
	while (src[i] != '\0')	
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}

	return dest;
}

