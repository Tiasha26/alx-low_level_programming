#include "main.h"
#include <stdio.h>

/**
 * print_binary - print binary representation of a number
 * @n: decimal number to print as binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int temp;
	int binum;

	if (n == 0)
	{
		printf("0");
		return;
	}

	for (temp = n, binum = 0; (temp >>= 1) > 0; binum++)
		;

	for (; binum >= 0; binum--)
	{
		if ((n >> binum) & 1)
			printf("1");
		else
			printf("0");
	}
}
