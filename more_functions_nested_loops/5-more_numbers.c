#include "main.h"
/**
  * more_numbers - prints 10 times the numbers
  *
  * Return: Always 0 success
  */
void more_numbers(void)
{
int n;
int m = 0;
while (m <= 9)
{
for (n = '0'; n <= '14'; n++)
{
_putchar(n);
}
_putchar('\n');
n++;
}
}
