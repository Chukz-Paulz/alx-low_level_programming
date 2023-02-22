#include "main.h"
#include <stdio.h>

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: integer to generate times table
 *
 * Return: void
 */
void print_times_table(int n)
{
int i, j, res;

if (n > 15 || n < 0)
return;

for (i = 0; i <= n; i++)
{
for (j = 0; j <= n; j++)
{
res = i * j;

if (j == 0)
printf("%d", res);
else
printf(",%3d", res);
}
printf("\n");
}
}
