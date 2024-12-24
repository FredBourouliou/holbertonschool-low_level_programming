#include "main.h"
#include <stdlib.h>

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * print_result - prints the result array
 * @result: the result array
 * @len: the length of the result
 */
void print_result(int *result, int len)
{
	int i, start = 0;

	/* Skip leading zeros */
	for (i = 0; i < len - 1; i++)
	{
		if (result[i] != 0)
			break;
		start++;
	}

	/* Print each digit */
	for (i = start; i < len; i++)
		_putchar(result[i] + '0');
	_putchar('\n');
}

/**
 * multiply - multiplies two positive numbers
 * @num1: first number string
 * @num2: second number string
 */
void multiply(char *num1, char *num2)
{
	int len1, len2, i, j, n1, n2, sum;
	int *result;

	len1 = _strlen(num1);
	len2 = _strlen(num2);

	/* Allocate memory for result */
	result = calloc(len1 + len2, sizeof(int));
	if (result == NULL)
		exit(98);

	/* Multiply each digit */
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			n1 = num1[i] - '0';
			n2 = num2[j] - '0';
			sum = result[i + j + 1] + (n1 * n2);
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	print_result(result, len1 + len2);
	free(result);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int i;

	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	num1 = argv[1];
	num2 = argv[2];

	/* Check if numbers only contain digits */
	for (i = 0; num1[i]; i++)
		if (!_isdigit(num1[i]))
		{
			_putchar('E');
			_putchar('r');
			_putchar('r');
			_putchar('o');
			_putchar('r');
			_putchar('\n');
			exit(98);
		}

	for (i = 0; num2[i]; i++)
		if (!_isdigit(num2[i]))
		{
			_putchar('E');
			_putchar('r');
			_putchar('r');
			_putchar('o');
			_putchar('r');
			_putchar('\n');
			exit(98);
		}

	/* Handle case when either number is 0 */
	if (num1[0] == '0' || num2[0] == '0')
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	multiply(num1, num2);
	return (0);
}
