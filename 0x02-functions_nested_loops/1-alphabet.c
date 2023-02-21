#include "main.h"

/**
 * print_alphabet - prints the alphabet in lowercase followed by a new line
 */
void print_alphabet(void)
{
char letter = 'a';

while (letter <= 'z')
{
_putchar(letter);
letter++;
}

_putchar('\n');
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
print_alphabet();
return (0);
}

