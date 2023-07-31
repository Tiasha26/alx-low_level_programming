#include "lists.h"

/**
 * listint_len - the number of elements in a listint_t linked list.
 * @h: pointer to the head of the list.
 * Return: the number of elements in the list.
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		count ++;
		h = h->next;
	}
	return (count);
}
