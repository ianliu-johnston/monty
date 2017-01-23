#include "monty.h"


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
	unsigned int line_number;
	ssize_t nr;
	char *line;
	size_t length;
	FILE *fp;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", av[0]);
		exit(EXIT_FAILURE);
	}
	h = NULL;
	flag = "stack";
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	line_number = 0;
	do {
		++line_number;
		line = NULL;
		length = 0;
		nr = getline(&line, &length, fp);
		if (nr > 0)
			execute(&h, line, line_number);
		else
			free(line);
	} while (nr >= 0);

	fclose(fp);
	free_stack(h);

	return (0);
}
