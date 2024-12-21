#include <stdio.h>

/**
 * main - prints first 98 Fibonacci numbers, starting with 1 and 2
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int n1 = 1, n2 = 2;
	unsigned long int n1_head, n1_tail, n2_head, n2_tail;
	unsigned long int head, tail, div = 1000000000;
	int count;

	printf("%lu, %lu", n1, n2);

	for (count = 3; count < 93; count++)
	{
		n1_tail = n1 % div;
		n1_head = n1 / div;
		n2_tail = n2 % div;
		n2_head = n2 / div;

		head = n1_head + n2_head;
		tail = n1_tail + n2_tail;
		if (tail >= div)
		{
			head += 1;
			tail -= div;
		}

		printf(", %lu%09lu", head, tail);
		n1 = n2;
		n2 = (head * div) + tail;
	}

	/* After 92 numbers, we need to handle numbers separately */
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

		printf(", %lu%09lu", head, tail);

		n1_head = n2_head;
		n1_tail = n2_tail;
		n2_head = head;
		n2_tail = tail;
	}
	printf("\n");
	return (0);
}
