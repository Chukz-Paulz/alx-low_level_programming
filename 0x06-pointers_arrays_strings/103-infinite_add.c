#include "main.h"
#include <stdio.h>

/**
 * infinite_add - Adds two numbers
 * @n1: First number
 * @n2: Second number
 * @r: Buffer to store result
 * @size_r: Size of buffer
 *
 * Return: Pointer to result or 0 if buffer is too small
 */

/* Add two numbers represented as strings */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
int i = 0, j = 0, k = 0, carry = 0, sum = 0;
int n1_len = 0, n2_len = 0, max_len = 0;

/* Calculate length of n1 */
while (n1[n1_len] != '\0')
{
n1_len++;
}

/* Calculate length of n2 */
while (n2[n2_len] != '\0')
{
n2_len++;
}

/* Calculate maximum length */
max_len = (n1_len > n2_len) ? n1_len : n2_len;

/* Check if result can fit in buffer */
if (max_len + 1 > size_r)
{
return 0;
}

/* Add numbers from right to left */
for (i = n1_len - 1, j = n2_len - 1, k = max_len; k >= 0; i--, j--, k--)
{
sum = carry;

if (i >= 0)
{
sum += n1[i] - '0';
}
if (j >= 0)
{
sum += n2[j] - '0';
}

carry = sum / 10;
r[k] = (sum % 10) + '0';
}

/* Add carry if necessary */
if (carry != 0) {
if (max_len + 2 > size_r)
{
return (0);
}

for (i = max_len + 1; i >= 1; i--)
{
r[i] = r[i - 1];
}

r[0] = carry + '0';
}

/* Add terminating null character */
if (max_len + 1 <= size_r)
{
r[max_len + 1] = '\0';
}

return (r);
}

