#include "main.h"
/**
 * print_square - prints a square, followed by a new line.
 * @size: the size of the square
 * return: always 0
 */
void print_square(int size)
{
int x, y;
if (size <= 0)
{
_putchar('\n');
}
else
{
for (x = 0; x < size; x++)
{
for (y = 0; y < size; y++)
{
_putchar(35);
}
_putchar('\n');
}
}
}
