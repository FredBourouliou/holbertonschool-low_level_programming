#include "main.h"
/**
 * sqrt_helper - function to find the natural square root
 * @n: The number to find the square root of
 * @x: The current number to test as a potential square root
 * Return: The natural square root
 */
int sqrt_helper(int n, int x)
{
if (x * x == n)
return (x);
if (x * x > n)
return (-1);
return (sqrt_helper(n, x + 1));
}
/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number to find the square root
 * Return: The natural square root of n, or -1 if it does not exist
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
return (sqrt_helper(n, 1));
}
