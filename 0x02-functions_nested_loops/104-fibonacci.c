#include <stdio.h>

/**
 * main - prints the first 98 fibonacci numbers
 * Return: 0 if successful
 */

int main(void)
{
	int count = 98;
	int prev = 1;
	int current = 2;
	int next;

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
