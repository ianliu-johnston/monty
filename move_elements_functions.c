#include "monty.h"

/*functions related to swapping and rotating elements*/


/**
 * swap - swap the values of the top and last elements
 * @h: head of the dll
 * @l: line number
 * opcode: swap
 */
void swap(stack_t **h, int l)
{
	int value0;

	if (!h || !*h)
	{
		printf("L%d: can't swap, stack too short\n", l);
		/*maybe we need 2 functions to get the right string*/
		free_stack(*h);
		free(command); /*free extern variable*/
		exit(EXIT_STATUS);
	}

	value0 = (*h)->n;

	if ((*h)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", l);
		free_stack(*h);
		free(command); /*free extern variable*/
		exit(EXIT_STATUS);
	}

	(*h)->n = ((*h)->next)->n;
	((*h)->next)->n = value0;
}


/**
 * rotl - the top element of the stack moves to the back
 * @h: head of the dll
 * @l: line number
 * opcode: rotl
 */
void rotl(stack_t **h, int l)
{
	(void) l;
	stack_t *node, *tmp;

	if (!h || !*h)
		return;
	if (!(*h)->next)
		return; /*one element in the stack*/

	node = pop(h);
	node->next = NULL;

	tmp = *h;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->previous = tmp;
}


/**
 * rotr - the last element of the stack moves on top
 * @h: pointer to dll
 * @l: line number
 * opcode: rotr
 */
void rotr(stack_t **h, int l)
{
	(void) l;
	stack_t *node;

	if (!h || !*h)
		return;
	if (!(*h)->next)
		return; /*one element in the stack*/

	node = dequeue(h);
	node->previous = NULL;

	node->next = *head;
	(*head)->previous = node;
	*head = node;
}
