#include "main.h"

/**
 * _islower - checks input is lowercase
 * main - uses built-in function
 * Return: 0 if successful
 */

int _islower(int c)
{
	int alph;

	alph = 0;

	if (c >= 'a' && c <= 'z')
	{
		alph = 1;
	}
	return (alph);
}
