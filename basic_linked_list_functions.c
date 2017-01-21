#include "monty.h"

/**
 * add_node - push or enqueue an element at the beginning of the stack
 * @head: pointer to dll
 * @n: value to add
 * Return: pointer to new node or NULL
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new;


	if (!head)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head)
		(*head)->prev = new;
	*head = new;
	return (new);
}


/**
 * free_stack - free a dll of int
 * @head: a pointer to a dll
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}



/**
 * pull - return the node at the beginning
 * @head: pointer to a dll
 * Return: pointer to the node or NULL
 */
stack_t *pull(stack_t **head)
{
	stack_t *tmp;

	if (!head || !*head)
		return (NULL);

	tmp = *head;
	*head = (*head)->next;

	if(*head)
		(*head)->previous = NULL;

	return (tmp); /*remember to free it*/
}


/**
 * dequeue - return the node at the end
 * @head: pointer to a dll
 * Return: pointer to node or NULL
 */
stack_t *dequeue(stack_t **head)
{
	stack_t *h;

	if (!head || !*head)
		return (NULL);

	h = *head;
	while (h->next != NULL)
		h = h->next;

	if (h->previous)
		(h->previous)->next = NULL;
	else
		/*the queue had one element or less*/
		*head = NULL;

	return (h);
}
