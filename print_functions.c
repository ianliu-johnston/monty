#include "monty.h"

/* these functions are used to print all or an element of the linked list.
 * they correspond to the opcode in the description
 */


/**
 * print_ints - print all the elements in a dll as numbers
 * @h: pointer to dll
`* @l: line number
 * opcode: pall
 */
void print_ints(const stack_t **h, int l)
{
	(void) l;

	if (!h)
		return;

	while (*h != NULL)
	{
		printf("%d\n", (*h)->n);
		*h = (*h)->next;
	}
	return (count);
}


/**
 * print_string - print all the elements in a dll as chars
 * @h: pointer to dll
 * @l: line number
 * opcode: pstr
 */
void print_string(const stack_t **h, int l)
{
	(void) l;

	if (!h || !*h)
		puts("");

	while (*h != NULL && (*h)->n > 0 && (*h)->n < 127)
	{
		printf("%c\n", (*h)->n);
		*h = (*h)->next;
	}
	return (count);
}


/**
 * pchar - peek the top of the stack
 * @h: pointer to dll
 * @l: line number
 * opcode: pchar
 */
void pint(const stack_t **h, int l)
{

	if (!h || !*h)
	{
		printf("L%d: can't pint, %s empty\n", l, flag);
		free_stack(*h);
		exit(EXIT_STATUS);
	}

	printf("%c\n", (*h)->n);
}




/**
 * pchar - peek the top of the stack
 * @h: pointer to dll
 * @l: line number
 * opcode: pchar
 */
void pchar(const stack_t **h, int l)
{
	int value;

	if (!h || !*h)
	{
		printf("L%d: can't pchar, %s empty\n", l, flag);
		free_stack(*h);
		exit(EXIT_STATUS);
	}

	value = (*h)->n;
	if (value <0 || value > 127)
		printf("L%d: can't pchar, value out of range\n", l);
	else
		printf("%c\n", value);
}
