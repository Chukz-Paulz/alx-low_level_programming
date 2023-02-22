#include "main.h"

/**
 * _abs - computes the absolute value of an integer
 * @n: the integer to compute the absolute value of
 *
 * Return: the absolute value of n
 */
int _abs(int n)
{
/* check if n is negative */
if (n < 0)
{
/* if so, return the negation of n */
return (-n);
}
/* otherwise, return n */
return (n);
}
