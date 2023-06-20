#include "main.h"

/**
 * _abs - determine the absolute value of an integer
 * @i: variable to determine the absolute value of an integer
 * Return: i if succesful
 */

int print_last_digit(int i)
{
	i %= 10;

	if (i < 0)
		i *= -1;
	i += 48;
	_putchar(i);

	return (i - '0');
}
