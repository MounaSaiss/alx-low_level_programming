#include "main.h"

/**
 * flip_bits - bits you would need to flip from one to another
 * @n: the number
 * @m: the other number
 * Return: an unsigned integer
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m;
	unsigned int nbit = 0;

	while (xor)
	{
		nbit += (xor & 1);
		xor >>= 1;
	}
	return (nbit);
}
