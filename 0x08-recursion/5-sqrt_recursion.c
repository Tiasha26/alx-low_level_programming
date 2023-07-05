#include "main.h"
#include <stdio.h>

/**
 * sqrt_recursive - Helper function to calculate the square root recursively
 * @n: The number to find the square root of
 * @guess: Current approximation of the square root
 * Return: The natural square root approximation, or -1 if no exact square root
 * is found.
 */
int sqrt_recursive(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	else if (guess * guess > n)
		return (-1);
	else
		return (sqrt_recursive(n, guess + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to find the square root of.
 * Return: The natural square root, or -1 if n does not have a
 * natural square root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqrt_recursive(n, 0));
}

