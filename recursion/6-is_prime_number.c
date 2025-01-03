#include "main.h"
/**
 * check_prime - Helper function to determine if a number is prime
 * @n: The number to check
 * @i: The current divisor to test
 * Return: 1 if n is prime, 0 if not
 */
int check_prime(int n, int i)
{
if (i >= n)
return (1);
if (n % i == 0)
return (0);
return (check_prime(n, i + 1));
}
/**
 * is_prime_number - Checks if a number is a prime
 * @n: The number to check
 * Return: 1 if n is a prime number, 0 otherwise
 */
int is_prime_number(int n)
{
if (n <= 1)
return (0);
return (check_prime(n, 2));
}
