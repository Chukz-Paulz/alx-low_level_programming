#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: Prints all possible different combinations of two digits.
 * Numbers must be separated by a comma and a space.
 * The two digits must be different.
 * 01 and 10 are considered the same combination of the two digits 0 and 1.
 * Only the smallest combination of two digits is printed.
 * Numbers are printed in ascending order with two digits.
 * putchar function is used, with a maximum of five putchar calls.
 * No variables of type char are used.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int i, j;
for (i = 0; i < 9; i++)
{
for (j = i + 1; j <= 9; j++)
{
putchar(i + '0');
putchar(j + '0');
if (i != 8 || j != 9)
{
putchar(',');
putchar(' ');
}
}
}
putchar('\n');
return (0);
}
