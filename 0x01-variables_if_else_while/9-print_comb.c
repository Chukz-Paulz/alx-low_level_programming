#include <stdio.h>
/**
 * main - Entry point
 *
 * Prints all possible combinations of single-digit numbers.
 * Separates Numbers by commas and spaces and printed in ascending order.
 * Uses putchar function exclusively, with a maximum of four putchar calls.
 * No variables of type char are used.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int n1, n2;
for (n1 = 0; n1 < 10; n1++)
{
for (n2 = n1 + 1; n2 < 10; n2++)
{
putchar(n1 + '0');
putchar(n2 + '0');
if (n1 != 8 || n2 != 9)
{
putchar(',');
putchar(' ');
}
}
}
putchar('\n');
return (0);
}
