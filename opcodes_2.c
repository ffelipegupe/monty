#include "monty.h"

/**
 * pop_h - function that removes the top element of a stack
 * @stack: stack
 * @line_number: number of lines
 *
 * Return: EXIT_FAILURE, on failure
 */
void pop_h(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_list((*stack));
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(tmp);
	if (*stack)
		(*stack)->prev = NULL;
}

/**
 * pint_h - function that prints the value at the top of aa stack
 * @stack: double linked list that makes the stack
 * @line_number: counter of lines
 *
 * Return: EXIT_FAILURE if failed
 */
void pint_h(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_list((*stack));
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
