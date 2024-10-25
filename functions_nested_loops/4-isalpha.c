#include "main.h"
/**
 * int _isalpha(int c)
 * @c: sign of a letter
 * Return: 1 for letter or 0 for anything else
 */
int _isalpha(int c)
{    
int c;
c = _isalpha('H');
_putchar(c + '0');
c = _isalpha('o');
_putchar(c + '0');
c = _isalpha(108);
_putchar(c + '0');
c = _isalpha(';');
_putchar(c + '0');
_putchar('\n');
return (0);
}
