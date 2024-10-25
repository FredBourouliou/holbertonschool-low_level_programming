#include "main.h"
/**
 * _abs - main entry
 * return: always 0 success
 */
int _abs(int)
{
int x = -4, y; 
y = _abs(x);
putchar("The absolute value of x is %d.\n", y);
return (0);
