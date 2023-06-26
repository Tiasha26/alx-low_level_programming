#include "main.h"

/**
 * rev_string - print a string in reverse followed by a new line
 * @s: string to be reversed
 */

void rev_string(char *s)
{
	int len, start, end;
	char temp;

	len = 0;
	start = 0;
	end = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	end = len - 1;
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		start++;
		end--;
	}
}
