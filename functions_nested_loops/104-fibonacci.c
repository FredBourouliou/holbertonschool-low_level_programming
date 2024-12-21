#include <stdio.h>

/**
 * print_fibonacci_part2 - prints the rest of Fibonacci numbers
 * @n1: first number
 * @n2: second number
 * @count: current count
 */
void print_fibonacci_part2(unsigned long int n1,
		unsigned long int n2, int count)
{
	unsigned long int n1_head, n1_tail, n2_head, n2_tail;
	unsigned long int head, tail, div = 1000000000;

	n1_tail = n1 % div;
	n1_head = n1 / div;
	n2_tail = n2 % div;
	n2_head = n2 / div;

	for (; count <= 98; count++)
	{
		head = n1_head + n2_head;
		tail = n1_tail + n2_tail;
		if (tail >= div)
		{
			head += 1;
			tail -= div;
		}

		if (head > 0)
			printf(", %lu%09lu", head, tail);
		else
			printf(", %lu", tail);

		n1_head = n2_head;
		n1_tail = n2_tail;
		n2_head = head;
		n2_tail = tail;
	}
	printf("\n");
}

/**
 * main - prints first 98 Fibonacci numbers, starting with 1 and 2
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int n1 = 1, n2 = 2, next;
	int count;

	printf("%lu, %lu", n1, n2);

	for (count = 3; count < 93; count++)
	{
		next = n1 + n2;
		printf(", %lu", next);
		n1 = n2;
		n2 = next;
	}

	print_fibonacci_part2(n1, n2, count);
	return (0);
}
