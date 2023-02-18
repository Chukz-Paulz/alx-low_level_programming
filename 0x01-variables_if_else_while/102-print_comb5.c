#include <stdio.h>
/**
 * main - Entry point
 *
 * Prints all possible combinations of two two-digit numbers.
 * The numbers range from 0 to 99 and are separated by a space.
 * All numbers are printed with two digits, with 1 printed as 01.
 * The combination of numbers is separated by comma, followed by a space.
 * The combinations of numbers are printed in ascending order.
 * The same combination of the numbers 0 and 1.
 * Only uses function and a maximum of eight putchar calls in the code.
 * We are not allowed to use any variable of type char.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int i, j;
for (i = 0; i < 100; i++)
{
for (j = i; j < 100; j++)
{
int a = i / 10;
int b = i % 10;
int c = j / 10;
int d = j % 10;
putchar(a + '0');
putchar(b + '0');
putchar(' ');
putchar(c + '0');
putchar(d + '0');
if (i != 99 || j != 99)
{
putchar(',');
putchar(' ');
}
}
}
return (0);
}
