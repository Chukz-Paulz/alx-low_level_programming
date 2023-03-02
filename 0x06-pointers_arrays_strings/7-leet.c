#include "main.h"

/**
 * leet - encode a string into 1337
 * @s: string to be encoded
 *
 * Return: pointer to encoded string
 */
char *leet(char *s)
{
	int i, j;
	char letter[] = "aeotlAEOTL";
	char number[] = "4307104310";

		for (i = 0; s[i] != '\0'; i++)
		{
			for (j = 0; letter[j] != '\0'; j++)
			{
				if (s[i] == letter[j])
				{
					s[i] = number[j];
					break;
			}
		}
	}

return (s);
}

