#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string to reverse
 */
void rev_string(char *s)
{
	int i = 0, j = 0;
	char temp;

	while (s[i] != '\0')
		i++;
	i--;

	while (j < i)
	{
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		j++;
		i--;
	}
}

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer to store result
 * @size_r: buffer size
 * Return: pointer to result, or 0 if result cannot be stored
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k = 0;
	int sum = 0, carry = 0;
	int len1 = 0, len2 = 0;

	/* Get lengths of numbers */
	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;

	/* Check if result can fit in buffer */
	if (len1 + 2 > size_r || len2 + 2 > size_r)
		return (0);

	i = len1 - 1;
	j = len2 - 1;

	/* Add digits from right to left */
	while (i >= 0 || j >= 0)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';

		carry = sum / 10;
		r[k] = (sum % 10) + '0';

		i--;
		j--;
		k++;
	}

	/* Add final carry if exists */
	if (carry)
	{
		if (k + 1 >= size_r)
			return (0);
		r[k] = carry + '0';
		k++;
	}

	r[k] = '\0';
	rev_string(r);

	return (r);
}
