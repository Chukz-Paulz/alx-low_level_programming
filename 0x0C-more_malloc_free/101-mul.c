#include <string.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>


int is_digit(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
		{
		return (0);
		}
		s++;
	}
	return (1);
}

void print_error(void)
{
	printf("Error\n");
	exit(98);
}

int main(int argc, char **argv)
{
	int i, j, k, carry, len1, len2;
	int *result;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		print_error();
	}

	len1 = 0;
	while (argv[1][len1])
	{
		len1++;
	}

	len2 = 0;
	while (argv[2][len2])
	{
		len2++;
	}

	result = malloc((len1 + len2) * sizeof(int));
	if (!result) 
	{
	return (1);
	}

	for (i = 0; i < len1 + len2; i++)
	{
		result[i] = 0;
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			k = i + j + 1;
			carry += (argv[1][i] - '0') * (argv[2][j] - '0') + result[k];
			result[k] = carry % 10;
			carry /= 10;
		}
		if (carry)
		{
		result[i + j + 1] += carry;
		}
	}

	i = 0;
	while (result[i] == 0 && i < len1 + len2 - 1)
	{
		i++;
	}
	for (; i < len1 + len2; i++)
	{
		_putchar(result[i] + '0');
	}
	_putchar('\n');
	free(result);
	return (0);
}
