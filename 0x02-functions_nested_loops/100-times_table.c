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
int i, j, result;

if (n > 15 || n < 0) {
return;
}

for (i = 0; i <= n; i++) {
for (j = 0; j <= n; j++) {
result = i * j;
if (j != 0) {
printf(", ");
}
if (result < 10 && j != 0) {
printf("   ");
} 
else if (result < 100) 
{
printf("  ");
} 
else 
{
printf(" ");
}
printf("%d", result);
}
printf("\n");
}
}
