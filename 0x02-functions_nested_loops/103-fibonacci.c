#include <stdio.h>

/**
 * main - Entry point. Prints the sum of the even-valued terms in the
 *        Fibonacci sequence up to a limit of 4,000,000.
 *
 * Return: Always 0.
 */
int main(void)
{
int prev = 1, curr = 2, next = 0, sum = 0;

while (curr <= 4000000)
{
if (curr % 2 == 0)
sum += curr;

next = prev + curr;
prev = curr;
curr = next;
}

printf("%d\n", sum);

return (0);
}

