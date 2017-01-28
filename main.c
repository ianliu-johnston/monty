#include "monty.h"

char *flag = "stack";

/**
 * main - main function to run monty
 * @ac: number of arguments
 * @av: list of arguments as strings
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	stack_t *h;
	int exec_err, fp;
	unsigned int line_number;
	ssize_t status;
	char *line;
	size_t length;

	if (ac != 2)
	{
		printf("USAGE: monty file\n"), exit(EXIT_FAILURE);
	}
	h = NULL;
	fp = open(av[1], O_RDONLY);
	if (fp == -1)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	line_number = 0;
	do {
		++line_number;
		line = NULL;
		length = 0;
		status = _getline(&line, &length, fp);
		if (status > 2)
		{
			exec_err = execute(&h, line, line_number);
			if (exec_err == -1)
				status = -2;
		}
		else
			free(line);
	} while (status >= 0);

	close(fp);
	free_stack(h), h = NULL;
	if (status == -1)
		return (0);
	exit(EXIT_FAILURE);
}
