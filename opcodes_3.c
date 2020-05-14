#include "monty.h"

/**
 * swap_h - function that swaps the top two elements of a stack
 * @stack: stack
 * @line_number: number of lines
 *
 * Return: EXIT FAILURE, on failure
 */
void swap_h(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		free_list((*stack));
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * nop_h - function that adds the top two elements of a stack
 * @stack: stack
 * @line_number: number of the line
 *
 * Return: nothing
 */
void nop_h(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * add_h - function that adds
 * @stack: stack
 * @line_number: number of lines
 *
 * Return: EXIT_FAILURE, on failure
 */
void add_h(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		free_list((*stack));
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop_h(stack, line_number);
}