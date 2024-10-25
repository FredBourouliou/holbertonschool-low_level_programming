#include "main.h"
/**
  * print_last_digit - Prints the last digit of a number
  * @n: The number to be treated
  *
  * Return: Value of the last digit of number
  */
int print_last_digit(int n)
{
int lastdigit;
lastdigit = n % 10;
if (lastdigit < 0)
_putchar(lastdigit * -1);
_putchar(lastdigit + '0');
return (lastdigit);
}
