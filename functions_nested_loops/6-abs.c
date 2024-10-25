#include "main.h"
#include <stdio.h>
/**
 * _abs - main entry
 * @n: the number
 * return: always 0 success
 */
int _abs(int n)
{
if (n < 0)
{
int abs_val;
abs_val = n * -1;
return (abs_val);
}
return (n);
}
