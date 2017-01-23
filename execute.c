#include "monty.h"


/**
 * execute - finds the function matching the opcode
 * @h: pointer to dll
 * @line: command line
 * @line_number: line number of the command line in the file
 */
void execute(stack_t **h, char *line, int line_number)
{
	int i;
	char *start_c;

	instruction_t instr[14] = {
		{"pall", pall},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pint", pint},
		{"pchar", pchar},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue}
		{"nop", nop},
		{NULL, NULL}
	};

	start_c = skip_spaces(line);
	if (start_c == NULL)
		return;

	if (_strncmp(start_c, "push", strlen("push")) == 0)
	{
		push(h, line, line_number);
		return;
	}

	for (i = 0; i < 14; ++i)
	{
		if (_strncmp(start_c, instr[i].opcode,
			    strlen(instr[i].opcode)) == 0)
		{
			free(line);
			line == NULL;
			instr[i].f(h, line_number);
			return;
		}
	}
	printf("L%d: unknown instruction ", line_number);
	while (*start_c && (*start_c != ' ' && *start_c != '\t'))
		putchar(*start_c++);
	putchar('\n');
	free(line);
	free_stack(*h);
	*h = NULL;
	exit(EXIT_FAILURE);
}
