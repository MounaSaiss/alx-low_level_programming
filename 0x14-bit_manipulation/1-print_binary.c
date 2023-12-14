#include "main.h"

/**
 * print_binary - print the binary repsentation of a number
 * @n: an integer number
 * Return: void
*/

void print_binary(unsigned long int n)
{
	unsigned long int m = n, count = 0;

	while (m)
	{
		m >>= 1;
		count++;
	}

	if (count)
	{
		while (count--)
		{
			if (n & (1L << count))
				_putchar('1');
			else
				_putchar('0');
		}
	}
	else
		_putchar('0');
}
