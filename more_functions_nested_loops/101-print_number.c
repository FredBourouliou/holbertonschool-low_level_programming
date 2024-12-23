#include "main.h"

/**
 * print_number - prints an integer using only _putchar
 * @n: integer to print
 */
void print_number(int n)
{
    int divisor = 1;
    int temp;

    if (n < 0)
    {
        _putchar('-');
        /* Handle INT_MIN case */
        if (n == -2147483648)
        {
            temp = -(n / 10);
            print_number(temp);
            _putchar('8');
            return;
        }
        n = -n;
    }

    /* Find the largest power of 10 less than n */
    temp = n;
    while (temp > 9)
    {
        divisor *= 10;
        temp /= 10;
    }

    /* Print each digit */
    while (divisor > 0)
    {
        _putchar((n / divisor) + '0');
        n %= divisor;
        divisor /= 10;
    }
}
