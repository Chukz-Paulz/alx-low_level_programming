#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * infinite_add - adds two numbers
 * @n1: the first number
 * @n2: the second number
 * @r: the buffer to store the result
 * @size_r: the size of the buffer
 *
 * Return: a pointer to the result or 0 if the result can't be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int i, j, k, carry, len1, len2;

    len1 = strlen(n1);
    len2 = strlen(n2);

    if (len1 > size_r || len2 > size_r)
        return 0;

    i = len1 - 1;
    j = len2 - 1;
    k = 0;
    carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int digit1 = i >= 0 ? n1[i] - '0' : 0;
        int digit2 = j >= 0 ? n2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;

        if (k >= size_r)
            return 0;

        r[k++] = sum % 10 + '0';
        carry = sum / 10;

        i--;
        j--;
    }

    r[k] = '\0';

    for (i = 0, j = k - 1; i < j; i++, j--)
    {
        char tmp = r[i];
        r[i] = r[j];
        r[j] = tmp;
    }

    return r;
}
