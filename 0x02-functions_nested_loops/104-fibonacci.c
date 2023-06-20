#include <stdio.h>

/**
 * main - prints the first 98 fibonacci numbers
 * Return: 0 if successful
 */

int main(void)
{
	int count = 98;
	unsigned int prev = 1;
	unsigned int current = 2;
	unsigned int next;

	printf("%u, %u", prev, current);

	for (int i = 3; i <= count; i++)
	{
		next = prev + current;
		printf(", %u", next);
		prev = current;
		current = next;
	}
	printf('\n');
	return (0);
}
