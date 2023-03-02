#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number to add
 * @n2: second number to add
 * @r: buffer to store result
 * @size_r: size of buffer
 *
 * Return: pointer to result, or 0 if result can't be stored in buffer
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, l1, l2, sum, carry;

	/* find lengths of n1 and n2 */
	for (l1 = 0; n1[l1]; l1++)
		;
	for (l2 = 0; n2[l2]; l2++)
		;

	if (l1 > size_r || l2 > size_r)
		return (0);

	i = l1 - 1;
	j = l2 - 1;
	k = 0;
	carry = 0;

	/* add digits from n1 and n2, and store result in buffer */
	while (i >= 0 || j >= 0 || carry > 0)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';
		r[k++] = (sum % 10) + '0';
		carry = sum / 10;
	}
	r[k] = '\0';

	/* reverse the result */
	for (i = 0, j = k - 1; i < j; i++, j--)
	{
		char temp = r[i];
		r[i] = r[j];
		r[j] = temp;
	}

	return (r);
}
