#include <stdio.h>
/**
 * main - Starting point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;
	int num1;

	for (num = '0'; num <= '9'; num++)
	{
		for (num1 = '0'; num1 <= '9'; num1++)
		{
			putchar(num);
			putchar(num1);
			if (num == '9' && num1 == '9')
				continue;
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
