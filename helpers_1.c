#include "monty.h"
/**
 * parse - function that parses strings into tokens
 * @buff: buffer
 * @stack: stack
 * @line_number: number of lines
 *
 * Return: nothing
 */

void parse(char *buff, stack_t **stack, unsigned int line_number)
{
	char *chn, *tmp;

	chn = strtok(buff, " \n\t");
	tmp = strtok(NULL, " \n\t");
	glob.data = tmp;
	if (chn && chn[0] != '#')
		get_opcode(stack, line_number, chn);
}

/**
 * check_digit - function that checks a digit existance
 * @chr: character to be checked
 *
 * Return: 0, on success; 1, otherwise
 */
int check_digit(int chr)
{
	return ((chr >= '0' && chr <= '9') ? 1 : 0);
}
