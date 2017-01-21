#include "monty.h"

/**
 * print_ints - print all the elements in a dll as numbers
 * @h: pointer to dll
 * Return: size of dll
 */
size_t print_ints(const stack_t *h)
{
	size_t count;

	count = 0;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		++count;
		h = h->next;
	}
	return (count);
}

/*no pchar, I guess we do not need it, all can be done in function*/

/**
 * print_string - print all the elements in a dll as chars
 * @h: pointer to dll
 * Return: size of dll
 */
size_t print_string(const stack_t *h)
{
	size_t count;

	count = 0;
	if (!h)
		puts("");

	while (h != NULL && h->n > 0 && h->n < 127)
	{
		printf("%c\n", h->n);
		++count;
		h = h->next;
	}
	return (count);
}
