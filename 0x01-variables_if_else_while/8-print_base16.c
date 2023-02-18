/**
 * main - Entry point
 *
 * Description: Prints all the numbers of base 16 in lowercase
 *              followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int num = 0;
char letter = 'a';
while (num < 10)
{
putchar(num + '0');
num++;
}
while (letter < 'g')
{
putchar(letter);
letter++;
}
putchar('\n');
return (0);
}
