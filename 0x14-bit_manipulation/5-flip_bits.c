#include "main.h"
#include <stdio.h>

/**
 * flip_bits - counts the number of the bits to flip to get from n to m.
 * @n: the first number
 * @m: the second number
 *
 * Return: the number of bits needed to flip.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int results = n ^ m;
	unsigned int count = 0;

	while (results > 0)
	{
		count += results & 1;
		results >>= 1;
	}
	return (count);
}
