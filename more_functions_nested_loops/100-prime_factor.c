#include <stdio.h>
#include <math.h>

/**
 * main - finds and prints the largest prime factor of 612852475143
 * Return: Always 0
 */
int main(void)
{
    long n = 612852475143;
    long largest = -1;
    long i;

    /* Divide by 2 until the number becomes odd */
    while (n % 2 == 0)
    {
        largest = 2;
        n = n / 2;
    }

    /* Check for odd factors up to square root */
    for (i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            largest = i;
            n = n / i;
        }
    }

    /* If n is still greater than 2, it is the largest prime factor */
    if (n > 2)
        largest = n;

    printf("%ld\n", largest);
    return (0);
}
