#include <stdio.h>

/**
 *main - Finds and prints the first 98 Fibonacci numbers,
 * starting with 1 and 2,
 * separated by comma and space, followed by a new line.
 *
 * Return: Always (0).
 */

int main(void)
{
int i;
unsigned long curr = 1, prev = 0, temp;
printf("1, 2, ");
for (i = 2; i < 98; i++)
{
temp = curr;
curr = curr + prev;
prev = temp;
printf("%lu", curr);
if (i < 97)
{
printf(", ");
}
}
printf("\n");
return (0);
}
