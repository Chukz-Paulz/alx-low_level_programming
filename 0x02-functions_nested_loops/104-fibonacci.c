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
int a = 1;
int b = 2;
int sum = 0;

printf("%d, %d", a, b);
for (int i = 3; i <= n; i++)
{
sum = a + b;
printf(", %d", sum);
a = b;
b = sum;
}
printf("\n");
return (0);
}

