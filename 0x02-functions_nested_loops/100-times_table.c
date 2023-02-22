#include "main.h"
#include <stdio.h>

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the highest number to print the times table for
 *
 * Return: void
 */
void print_times_table(int n)
{
if (n > 15 || n < 0)
return;

for (int i = 0; i <= n; i++) {
for (int j = 0; j <= n; j++) {
int product = i * j;
if (j != 0)
printf(", ");
if (product < 10)
printf("  %d", product);
else if (product < 100)
printf(" %d", product);
else
printf("%d", product);
}
printf("\n");
}
}
