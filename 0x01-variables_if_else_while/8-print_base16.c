#include <stdio.h>
/**
 * main - Starting point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int digit;
	int digit1;

	for (digit = '0'; digit <= '9'; digit++)
	{
		putchar(digit);
	}
	for (digit1 = 'a'; digit1 <= 'f'; digit1++)
	{
		putchar(digit1);
	}
	putchar('\n');
	return (0);
}
