#include "main.h"

/**
 * is_b - check the binary number
 * @b: the char number
 * Return: 0 or 1
 */

int is_b(const char *b)
{
	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);
		b++;
		if (!*b)
			return (1);
	}
	return (0);
}

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: the char number
 * Return: the converted number
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int i, j, sum = 0;

	if (b == NULL)
		return (0);
	if (is_b(b))
	{
		for (i = 0; b[i]; i++)
			;
		for (j = 0; j < i; j++)
			sum += (b[i - j - 1] - '0') * (1 << j);
		return (sum);
	}
	return (0);
}
