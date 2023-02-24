#include "main.h"

int main(void)
{
int num = 612852475143;
int i;

while (num % 2 == 0) 
{
num /= 2;
}


for (i = 3; i <= sqrt(num); i += 2) 
{
while (num % i == 0) 
{
num /= i;
}
}

if (num > 1) 
{
i = num;
}

while (i > 0) 
{
_putchar(i % 10 + '0');
i /= 10;
}
_putchar('\n');

return (0);
}

