#include "main.h"
/**
 *  print-alphabet - prints the alphabet
 *  main - Starting point
 *  Return: 0 if successful
 */
void print_alphabet(void)
{
	char alph;

	for (alph = 'a'; alph <= 'z'; alph++)
	{
		_putchar(alph);
	}

	_putchar('\n');
}
