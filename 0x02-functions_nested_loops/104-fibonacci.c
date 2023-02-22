#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
unsigned int fib1 = 1, fib2 = 2, next_fib;
int i;

printf("%u, %u", fib1, fib2);

for (i = 3; i <= 98; i++)
{
next_fib = fib1 + fib2;
printf(", %u", next_fib);
fib1 = fib2;
fib2 = next_fib;
}

printf("\n");
return (0);
}

