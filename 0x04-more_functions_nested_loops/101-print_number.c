#include "main.h"
/**
 * print_number - a function that prints an integer
 * @n: input
 * Return: void
 */
void print_number(int n)
{
int digit_count = 0, divisor = 1, i;
char digit;

if (n < 0) {
_putchar('-');
n = -n;
    }

/* count number of digits in n */
for (i = n; i > 0; i /= 10) {
digit_count++;
divisor *= 10;
}
divisor /= 10;

/* print each digit of n */
for (i = 0; i < digit_count; i++) {
digit = (n / divisor) + '0';
_putchar(digit);
n %= divisor;
divisor /= 10;
    }

/* print 0 if n is 0 */
if (digit_count == 0) {
putchar('0');
}
}

