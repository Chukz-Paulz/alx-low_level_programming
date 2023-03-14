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
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char **tab;

	tab = strtow("      ALX School         #cisfun      ");
	if (tab == NULL)
	{
		_putchar('F');
		_putchar('a');
		_putchar('i');
		_putchar('l');
		_putchar('e');
		_putchar('d');
		_putchar('\n');
		return (1);
	}
	print_tab(tab);
	return (0);
}

