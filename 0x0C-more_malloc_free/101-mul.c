#include <string.h>
#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * mul - multiplies two positive numbers
 * @num1: the first number
 * @num2: the second number
 *
 * Return: a pointer to the result, or NULL if an error occurred
 */
char *mul(char *num1, char *num2)
{
	int len1, len2, i, j, carry, n1, n2, res;
	char *result;

	len1 = strlen(num1);
	len2 = strlen(num2);
	result = calloc(len1 + len2 + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	for (i = len1 - 1; i >= 0; i--)
	{
		if (!_isdigit(num1[i]))
		{
			free(result);
			return (NULL);
		}
		carry = 0;
		n1 = num1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			if (!_isdigit(num2[j]))
			{
				free(result);
				return (NULL);
			}
			n2 = num2[j] - '0';
			res = n1 * n2 + carry + result[i + j + 1];
			result[i + j + 1] = res % 10;
			carry = res / 10;
		}
		result[i + j + 1] = carry;
	}
	return (result);
}

/**
 * main - multiplies two positive numbers
 * @argc: the number of arguments
 * @argv: the argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	int i, j;
	char *result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (!_isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (98);
			}
		}
	}
	result = mul(argv[1], argv[2]);
	if (result == NULL)
	{
		printf("Error\n");
		return (98);
	}
	for (i = 0; result[i] == 0; i++)
		;
	if (result[i] == '\0')
		printf("0\n");
	else
	{
		for (; result[i]; i++)
			putchar(result[i] + '0');
		putchar('\n');
	}
	free(result);
	return (0);
}
