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
int num1, num2;
for (num1 = 0; num1 < 9; num1++)
{
for (num2 = num1 + 1; num2 <= 9; num2++)
{
putchar((num1 % 10) + '0');
putchar(',');
putchar(' ');
putchar((num2 % 10) + '0');
if (num1 != 8 || num2 != 9)
{
putchar(',');
putchar(' ');
}
}
}
putchar('\n');
return (0);
}
