#include "monty.h"

/**
 * push_h - function that pushes an element to the stack.
 * @stack: pointer to the stack
 * @line_number: line number
 *
*/
void push_h(stack_t **stack, unsigned int line_number)
{
	stack_t  *new_node, *tmp;
	int i, j = 1, dig;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ fprintf(stderr, "USAGE: monty file\n");
		free_list(new_node);
		exit(EXIT_FAILURE); }
	if (glob.data)
	{
		for (i = 0; glob.data[i] != '\0'; i++)
		{
			if (glob.data[i] >= 48 && glob.data[i] <= 57)
				j = 0;
			else
				j = 1;
		}
		if (j == 0)
			dig = atoi(glob.data);
		else
		{ fprintf(stderr, "L%u: usage: push integer\n",
				line_number);
			free_list((*stack));
			free(new_node);
			exit(EXIT_FAILURE); }
	}
	else
	{ fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_list((*stack));
		free(new_node);
		exit(EXIT_FAILURE); }
	new_node->n = num;
	new_node->next = *stack;
	new_node->prev = NULL;
	tmp = *stack;
	if (*stack != NULL)
		tmp->prev = new_node;
	*stack = new_node;
}

/**
 * pall_h - function that prints the values on the stack
 * @stack: stack
 * @line_number: number of lines
 *
 * Return: Nothing
 */
void pall_h(stack_t **stack, unsigned int line_number)
{
	stack_t *ff_stack;
	(void)line_number;

	ff_stack = *stack;
	for (; ff_stack; ff_stack = ff_stack->next)
		printf("%d\n", ff_stack->n);
}
