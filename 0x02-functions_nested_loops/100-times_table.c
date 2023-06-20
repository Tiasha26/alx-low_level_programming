#include "main.h"
#include <stdio.h>

/**
 * print_times_table - prints the n times tables.
 * @n: The number to generate the times table for.
 */

void print_times_table(int n)
{
	if (n < 0 || n > 15)
		return;

	int i, j, product:

		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				product = i * j;
				if (j != 0)
					printf(", ");

				if (product < 10)
					printf(" %d", product);
				else if (product < 100)
					printf(" %d", product);
				else 
					print("%d", product);
			}
			printf("\n");
		}
}
