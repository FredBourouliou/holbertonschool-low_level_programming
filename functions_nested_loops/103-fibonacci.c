#include <stdio.h>

/**
 * main - finds and prints the sum of the even-valued terms
 * in the Fibonacci sequence under 4,000,000
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int n1 = 1, n2 = 2, next;
	long int sum = 2;  /* Start with 2 since it's the first even number */

	while (1)
	{
		next = n1 + n2;
		if (next > 4000000)
			break;
		if (next % 2 == 0)
			sum += next;
		n1 = n2;
		n2 = next;
	}
	printf("%ld\n", sum);
	return (0);
}
