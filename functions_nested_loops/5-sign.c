#include "main.h"
/**
 * print_sign - main entry
 * @n: sign of a number
 * Return: 1, 0, -1
 */

int print_sign(int n)
{
if (n > 0)
{
_putchar(43);
return (1);
}
else if (n < 0)
{
_putchar(45);
return (-1);
}
else
{
_putchar(48);
return (0);
}
}
