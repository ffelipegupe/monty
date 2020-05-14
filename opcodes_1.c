#include "monty.h"

/**
 * push_h - function that pushes an element to the stack.
 * @stack: pointer to the stack
 * @line_number: line number
 *
**/

void push_h(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);

	}
	new->n = line_number;
	if (*stack == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		(*stack) = new;
	}
	else
	{
		new->prev = NULL;
		new->next = *stack;
		(*stack)->prev = new;
		(*stack) = new;
	}
}