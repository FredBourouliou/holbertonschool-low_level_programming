#include "main.h"
/**
 * print_triangle - function that prints a triangle
 * @size: the size of the triangle
 * return: empty
 */
void print_triangle(int size)
{
int x, y;
if (size <= 0)
{
_putchar('\n');
}
else
{
for (x = 0; x < size; --x)
{
for (y = 0; y < size; --y)
_putchar(35);
_putchar('\n');
}
}
}
