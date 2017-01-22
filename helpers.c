#include "monty.h"


/*maybe create _exit here, if ever we feel the need for it*/

/* these function do not take # into account yet*/

/**
 * skip_spaces - skip whitespaces
 * @s: a string
 *
 * Return: pointer to where is the first non space char or NULL
 */
char *skip_spaces(char *s)
{
	if (!s)
		return (NULL);

	while (*s && *s == ' ')
		++s;
	if (*s == '\0') /*empty string*/
		return (NULL);

	return (s);
}

/*use strncmp with this return value, opcode and strlen(opcode)*/


/**
 * reach_number - get the first number in a string
 * @s:
 * the string should contain only spaces and a valid opcode before
 * Return: a pointer to where the number is or NULL
 */
char *reach_number(char *s)
{
	if (!s)
		return (NULL);

	while (*s < '0' || *s > '9')
		++s;

	if (*s == '\0')
		return (NULL);
	return (s);
}

/*use atoi with this return value*/
