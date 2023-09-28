#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - converts a binary string to an unsigned int.
 * @b: a pointer to the binary string
 *
 * Return: the converted number or 0 if b is NULL,
 * there is one or more chars in the string b that is not 0 or 1
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i;

	if (b == NULL)
		return (0);
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		result = result * 2 + (b[i] - '0');
	}
	return (result);
}
