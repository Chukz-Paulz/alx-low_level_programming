#include <stdio.h>
/**
 * main - entry point
 *
 * Description: Prints the lowercase alphabet in reverse
 *              using only the putchar function
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int i;
for (i = 'z'; i >= 'a'; i--)
putchar(i);
putchar('\n');
return (0);
}
