#include "main.h"
#include <stdio.h>
/**
 * _abs - Computes the absolute value of an integer
 * @n: the number
 * return: absolute value of number zero
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
