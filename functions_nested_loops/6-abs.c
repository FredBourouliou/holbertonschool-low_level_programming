#include "main.h"
/**
 * _abs - main entry
 * return: always 0 success
 */
int _abs(int)
unsigned int number;
if (num < 0)
{
number = -num;
putchar('-');
}
else
{
number = num;
}
if (number / 10)
{
print_number(number / 10);
}
putchar('0' + (number % 10));
}
int main(void)
{
int num = 1028;
print_number(num);
putchar('\n');
return (0);
}
