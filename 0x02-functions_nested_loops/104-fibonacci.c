#include <stdio.h>

/**
 *main - Finds and prints the first 98 Fibonacci numbers,
 * starting with 1 and 2,
 * separated by comma and space, followed by a new line.
 *
 * Return: always (0).
 */
int main(void)
{
int n = 98;
int a = 1, b = 2, c;

printf("%d, %d", a, b);

for (int i = 3; i <= n; i++)
{
c = a + b;
printf(", %d", c);
a = b;
b = c;
}

printf("\n");

return (0);
}

