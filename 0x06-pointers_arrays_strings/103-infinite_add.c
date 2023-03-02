#include "main.h"

/**
 * infinite_add - Adds two numbers.
 * @n1: The first number to be added.
 * @n2: The second number to be added.
 * @r: Pointer to the buffer where the result will be stored.
 * @size_r: The size of the buffer.
 *
 * Return: A pointer to the result, or 0 if the result can't be stored.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
int i, j, k, l1, l2, sum, carry = 0;

for (l1 = 0; n1[l1]; l1++)
	;
for (l2 = 0; n2[l2]; l2++)
	;
if (l1 + 2 > size_r || l2 + 2 > size_r)
return (0);
i = l1 - 1, j = l2 - 1, k = 0;
while (i >= 0 || j >= 0 || carry)
{
sum = carry;
if (i >= 0)
sum += n1[i--] - '0';
if (j >= 0)
sum += n2[j--] - '0';
if (k + 1 < size_r)
r[k++] = sum % 10 + '0';
carry = sum / 10;
}
if (k == 0)
{
r[k++] = '0';
}
if (k + 1 > size_r)
{
return (0);
}
r[k] = '\0';
for (i = 0, j = k - 1; i < j; i++, j--)
{
char c = r[i];
r[i] = r[j];
r[j] = c;
}
return (r);
}

