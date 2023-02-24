#include <stdio.h>
#include <math.h>

/**
 * main - prints prime factors of 612852475143
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
int num = 612852475143;
int i;

for (i = 2; i <= sqrt(num); i++) 
{
while (num % i == 0) {
num /= i;
}
}

if (num > 1) 
{
i = num;
}

printf("%ld\n", i);
return (0);
}

