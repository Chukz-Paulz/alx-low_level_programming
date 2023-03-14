#include "main.h"
#include <stdlib.h>

/**
 * print_tab - Prints an array of strings
 * @tab: The array to print
 *
 * Return: nothing
 */
void print_tab(char **tab)
{
	int i, j;

	for (i = 0; tab[i] != NULL; ++i)
	{
		for (j = 0; tab[i][j] != '\0'; ++j)
		{
			_putchar(tab[i][j]);
		}
		_putchar('\n');

	}
	return (1);
}

