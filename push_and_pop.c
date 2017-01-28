#include "monty.h"

/*push and pop functions*/


/**
 * push - add an element to the stack/queue
 * @h: pointer to dll
 * @line: pointer to line
 * @l: line number
 * Return: 0 on success -1 on failure
 */
int push(stack_t **h, char *line, unsigned int l)
{
	char *start_n;
	stack_t *node;

	start_n = reach_number(line);
	if (start_n == NULL)
	{
		printf("L%d: usage: push integer\n", l);
		free(line);
		return (-1);
	};

	if (_strcmp(flag, "stack") == 0)
		node = add_node(h, atoi(start_n));
	else
		node = add_node_end(h, atoi(start_n));

	free(line);
	if (node == NULL)
	{
		puts("Error: malloc failed");
		return (-1);
	}
	return (0);
}

/**
 * pop - pull an element from the stack or queue
 * @h: pointer to dll
 * @l: line number
 */
void pop(stack_t **h, unsigned int l)
{
	stack_t *node;

	node = pop_s(h);

	if (node == NULL)
	{
		printf("L%d: can't pop an empty %s\n", l, flag);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	free(node);
}
