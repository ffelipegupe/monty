#include "monty.h"
/**
 * get_opcode - function that looks for the opcode
 * @func: function to find
 * @stack: stack to be use
 * @line_number: number of lines
 *
 * Return: EXIT_FAILURE on failure..
 */

void get_opcode(stack_t **stack, unsigned int line_number, char *func)
{
	int i = 0;

	instruction_t ops_cmd[] = {
		{"push", push_h},
		{"pall", pall_h},
		{"pop", pop_h},
		{"pint", pint_h},
		{"swap", swap_h},
		{"add", add_h},
		{"nop", nop_h},
		{NULL, NULL}
	};
	while (ops_cmd[i].opcode)
	{
		if (strcmp(ops_cmd[i].opcode, func) == 0)
		{
			ops_cmd[i].f(stack, line_number);
			break;
		}
		i++;
	}

	if (!ops_cmd[i].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, func);
		free_list((*stack));
		exit(EXIT_FAILURE);
	}
}
