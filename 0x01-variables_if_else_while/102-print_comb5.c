#include <stdio.h>
/**
 * main - Starting point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num1, num2;

	for (num1 = 0; num1 <= 99; num1++)
	{
		for (num2 = num1; num2 <= 99; num2++)
		{
			putchar('00' + num1 / 10);
			putchar('00' + num1 % 10);
			putchar(' ');
			putchar('00' + num2 / 10);
			putchar('00' + num2 % 10);

		if (num1 != 99 || num2 != 99)
		{
			putchar(',');
			putchar(' ');
		}
		}
	}
	return (0);
}