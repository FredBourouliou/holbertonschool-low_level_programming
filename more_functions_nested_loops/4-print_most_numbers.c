#include "main.h"
/**
* print_most_numbers - prints the numbers
* Return: Always 0 (Success)
*/
void print_most_numbers(void)
{
int n;
for (n = '48'; n <= '57'; n++)
if (n != '50' && n != '52')
_putchar('0' + n);
_putchar('\n');
}
