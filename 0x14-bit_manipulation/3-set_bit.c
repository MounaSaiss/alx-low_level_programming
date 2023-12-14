#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index.
 * @n: the number
 * @index: the index
 * Return: an integer
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(size_t) * 8)
		return (-1);
	if (*n & (1 << index))
		return (1);
	*n = *n + (1 << index);
	return (1);
}
