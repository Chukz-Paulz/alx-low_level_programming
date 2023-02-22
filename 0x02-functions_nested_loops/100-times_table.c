#include "main.h"
/**
 * print_times_table - prints the n times table, starting with 0
 * @n: integer input
 */
void print_times_table(int n)
{
int i, j, prod;

if (n < 0 || n > 15)
return;

for (i = 0; i <= n; i++)
{
for (j = 0; j <= n; j++)
{
prod = i * j;

if (j == 0)
printf("%d", prod);
else if (prod < 10)
printf("   %d", prod);
else if (prod < 100)
printf("  %d", prod);
else
printf(" %d", prod);

if (j != n)
printf(",");
}
printf("\n");
}
}

