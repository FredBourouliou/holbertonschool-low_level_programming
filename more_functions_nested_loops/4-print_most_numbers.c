#include "main.h"
/**
* print_most_numbers - prints the numbers
* Return: Always 0 (Success)
*/
void print_most_numbers(void)
{
int n;
for (n = '0'; n <= '9'; n++)
if (n != '2' && n != '4')
putchar('0' + n);
putchar('\n');
return (0);
}
