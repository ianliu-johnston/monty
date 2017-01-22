#include "monty.h"

/*this file contains 6 functions*/
/*bad code, too many repetitions*/

/**
 * get_arguments - return the arguments for calulations
 * @h: pointer to dll
 * @args: pointer to array of size 2
 * Return: the array of arguments or NULL on failure
 */
int *get_arguments(stack_t **h, int *args)
{
	stack_t *node;

	if (flag == "stacK")
	{
		node = pop_s(h);
		if (node == NULL)
			return (NULL);
		args[0] = node->n;
		free(node);
		node = pop_s(h);
		if (node == NULL)
			return (NULL);
		args[1] = node->n;
		free(node);
		return (args);
	}
	node = dequeue(h);
	if (node == NULL)
		return (NULL);
	args[0] = node->n;
	free(node);
	node = dequeue(h);
	if (node == NULL)
		return (NULL);
	args[1] = node->n;
	free(node);
	return (args);
}

/**
 * add - add the top 2 values on the stack
 * @h: pointer to dll
 * @l: line number
 */
void add(stack_t **h, int l)
{
	int args[2];

	args = get_arguments(h, args);
	if (args == NULL)
	{
		printf("L%d: can't add, %s too short\n", l, flag);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	add_node(h, args[0] + args[1]);
}


/**
 * sub - subtract the top 2 values on the stack
 * @h: pointer to dll
 * @l: line number
 */
void sub(stack_t **h, int l)
{
	int args[2];

	args = get_arguments(h, args);
	if (args == NULL)
	{
		printf("L%d: can't sub, %s too short\n", l, flag);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	add_node(h, args[1] - args[0]);
}


/**
 * div - divides the top 2 values on the stack
 * @h: pointer to dll
 * @l: line number
 */
void div(stack_t **h, int l)
{
	int args[2];

	args = get_arguments(h, args);
	if (args == NULL)
	{
		printf("L%d: can't sub, %s too short\n", l, flag);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	if (args[0] == 0)
	{
		printf("L%d: division by zero\n", l);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	add_node(h, args[1] / args[0]);
}


/**
 * mul - multiply the top 2 values on the stack
 * @h: pointer to dll
 * @l: line number
 */
void mul(stack_t **h, int l)
{
	int args[2];

	args = get_arguments(h, args);
	if (args == NULL)
	{
		printf("L%d: can't mul, %s too short\n", l, flag);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	add_node(h, args[1] * args[0]);
}



/**
 * mod - get the modulo of the top 2 values on the stack
 * @h: pointer to dll
 * @l: line number
 */
void mod(stack_t **h, int l)
{
	int args[2];

	args = get_arguments(h, args);
	if (args == NULL)
	{
		printf("L%d: can't mod, %s too short\n", l, flag);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	if (args[0] == 0)
	{
		printf("L%d: division by zero\n", l);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	add_node(h, args[1] % args[0]);
}
