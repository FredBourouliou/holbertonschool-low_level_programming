#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number to check bits in
 * @index: index at which to check bit
 * Return: value of the bit at index, or -1 if error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;


	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);


	mask = 1UL << index;


	return ((n & mask) ? 1 : 0);
}
