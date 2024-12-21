#include <stdio.h>

/**
 * main - prints first 50 Fibonacci numbers, starting with 1 and 2
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int n1 = 1, n2 = 2, next;
	int count;

	printf("%ld, %ld", n1, n2);

	for (count = 3; count <= 50; count++)
	{
		next = n1 + n2;
		printf(", %ld", next);
		n1 = n2;
		n2 = next;
	}
	printf("\n");
	return (0);
}
