#include <stdio.h>

/**
 * print_buffer - Prints a buffer
 * @b: The buffer to print
 * @size: The number of bytes to print
 */
void print_buffer(char *b, int size)
{
int i, j;

if (size <= 0)
{
printf("\n");
return;
}

for (i = 0; i < size; i += 10)
{
printf("%08x: ", (unsigned long)i);

for (j = i; j < i + 10; j++)
{
if (j < size)
printf("%02x", *(b + j));
else
printf("  ");

if (j % 2 != 0)
printf(" ");
}

printf(" ");

for (j = i; j < i + 10 && j < size; j++)
{
if (*(b + j) >= 32 && *(b + j) <= 126)
printf("%c", *(b + j));
else
printf(".");
}

printf("\n");
}
}
