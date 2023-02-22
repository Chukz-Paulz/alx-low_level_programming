#include <stdio.h>
/**
 *main - A program that finds and prints the first 98 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line. The numbers are
 * separated by a comma and a space.
 *
 * Return: always (0) if program runs successfully.
 */
int main(void)
{
int n = 98;
int a = 1, b = 2;

printf("%d, %d, ", a, b);

for (int i = 3; i <= n; i++)
{
int c = a + b;
printf("%d", c);
if (i < n)
{
printf(", ");
}
a = b;
b = c;
}

printf("\n");
return (0);
}
