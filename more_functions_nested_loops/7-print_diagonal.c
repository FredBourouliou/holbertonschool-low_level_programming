#include "main.h"
/**
 * print_diagonal - function that draws a diagonal line on the terminal.
 * @n: he number of times the character \ should be printed
 * return: empty
 */
void print_line(int n)
{
int x;
if (n <= 0)
{
_putchar('\n');
}
else
{
for (x = 0; x < n; x++)
{
_putchar(92);
}
_putchar('\n');
}
}
