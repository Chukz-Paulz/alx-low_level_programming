#include <unistd.h>

/**
 * print_number - print an integer to stdout
 * @n: the integer to print
 */
void print_number(long n)
{
if (n < 0) 
{
n = -n;
write(1, "-", 1);
}
if (n / 10) 
{
print_number(n / 10);
}
write(1, &"0123456789"[n % 10], 1);
}

int main(void)
{
long num = 612852475143;
long i;

for (i = 2; i <= num; i++) 
{
while (num % i == 0) 
{
num /= i;
}
}

print_number(i);
write(1, "\n", 1);

return (0);
}

