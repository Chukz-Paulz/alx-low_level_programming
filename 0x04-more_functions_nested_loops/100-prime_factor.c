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

while (num % 2 == 0) 
{
num /= 2;
}

for (i = 3; i <= sqrt(num); i += 2) 
{
while (num % i == 0) 
{
num /= i;
}
}

if (num > 1) 
{
i = num;
}

_putchar("%d\n", i);

return (0);
}
